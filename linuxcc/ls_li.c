#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<dirent.h>
#include<pwd.h>
#include<errno.h>
#include<grp.h>
#include<time.h>
#include<stdlib.h>

#define PARAM_NONE 0
#define PARAM_A    1
#define PARAM_L    2
#define MAXROWLWN  80

int g_leave_len = MAXROWLWN;
int g_maxlen;  //存放某目录下最长文件名的长度

void my_err(const char *err_string, int line)
{
    fprintf(stderr,"line:%d",line);
    perror(err_string);
    exit(1);
}

void display_attribute(struct stat buf,char * name)  /*显示所有的状态信息*/
{
    char   buf_time[32];
    struct passwd *psd;
    struct group  *grp;

    if(S_ISLNK(buf.st_mode)) {   //链接文件
        printf("l");
    }else if(S_ISREG(buf.st_mode)){  //普通文件
        printf("-");
    }else if(S_ISDIR(buf.st_mode)){  //目录
        printf("d");
    }else if(S_ISCHR(buf.st_mode)){  //字符设备
        printf("c");
    }else if(S_ISBLK(buf.st_mode)){   //块设备
        printf("b");
    }else if(S_ISFIFO(buf.st_mode)){  //FIFO文件
        printf("f");
    }else if(S_ISSOCK(buf.st_mode)){   //socket文件
        printf("s");
    }

    if(buf.st_mode & S_IRUSR){ //用户的权限
        printf("r");
    }else 
    printf("-");
    if(buf.st_mode & S_IWUSR){
        printf("w");
    }else
    printf("-");
    if(buf.st_mode & S_IXUSR){
        printf("x");
    }else
    printf("-");


    if(buf.st_mode & S_IRGRP){ //用户组的权限
        printf("r");
    }else 
    printf("-");
    if(buf.st_mode & S_IWGRP){
        printf("w");
    }else
    printf("-");
    if(buf.st_mode & S_IXGRP){
        printf("x");
    }else
    printf("-");


    if(buf.st_mode & S_IROTH){ //其他用户的权限
        printf("r");
    }else 
    printf("-");
    if(buf.st_mode & S_IWOTH){
        printf("w");
    }else
    printf("-");
    if(buf.st_mode & S_IXOTH){
        printf("x");
    }else
    printf("-");

    printf(" ");

    /* printf("%d\n",buf.st_mode); */
    /* getchar(); */
    /* getchar(); */

    psd=getpwuid(buf.st_uid);
    grp=getgrgid(buf.st_gid);

    printf("%4d  ",buf.st_nlink);
    printf("%-8s",psd->pw_name);
    printf("%-8s",grp->gr_name);

    printf("%6d",buf.st_size);//文件的大小
    strcpy(buf_time,ctime(&buf.st_mtime));  //文件的最后修改时间
    //ctime函数的作用为把时间转化为字符串
    buf_time[strlen(buf_time)-1]='\0';
    printf("  %s",buf_time);
}

void display_single(char *name)
{
    int i,len;
    if(g_leave_len<g_maxlen)
    {
        putchar('\n');
        g_leave_len=MAXROWLWN;
    }

    len=strlen(name);
    len=g_maxlen-len;
    printf("%-s",name);
    for(int i=0;i<len;i++) putchar(' ');
    printf("  ");  //两个空格
    g_leave_len-=(g_maxlen+2);//一行中剩下的字符数
}

void display(int flag,char *pathname)  //传入一个路径名 
{
    int i,j;
    struct stat buf;
    char name[_PC_NAME_MAX+1];  //代表名称的最长值 不同系统可能不同

    for(i=0,j=0;i<strlen(pathname);i++)
    {
        if(pathname[i]=='/')  //目录之间的分隔符
        {
            j=0;continue;
        }
        name[j++]=pathname[i];
    }
    name[j]='\0';
    //fstat(pathname,&buf);
    if(lstat(pathname,&buf)==-1)
    {
        my_err("stat",__LINE__);  //stat函数出现错误 进行精确到行的报错
    } 
    //感觉是我机子的原因 使用了stat函数以后name值发生改变
    //仅支持-a -l选项 即四种情况
    switch (flag)
    {
        case PARAM_NONE:
            if(name[0]!='.')    //一般情况不显示隐藏文件
            display_single(name);
            break;
        case PARAM_A:
            display_single(name);
            break;
        case PARAM_L:
            if(name[0]!='.')
            {
                display_attribute(buf,name);
                printf("  %s\n",name);
            }
            break;
        case PARAM_A+PARAM_L:
                display_attribute(buf,name);
                printf("  %s\n",name);
                break;
        default:
            break;
    }
}

void display_dir(int flag_param,char * path)
{
    DIR *dir;
    struct dirent *ptr;
    int count=0;
    char filename[256][_PC_PATH_MAX+1],temp[_PC_PATH_MAX+1];

    dir=opendir(path);
    if(dir==NULL)
    {
        my_err("opendir",__LINE__);
    }
    //统计出最长文件名长度和文件总数
    while((ptr=readdir(dir))!=NULL)
    {
        if(g_maxlen<strlen(ptr->d_name))
        {
            g_maxlen=strlen(ptr->d_name);
        }
        count++;
    }
    closedir(dir);
    if(count>256)
    {
        my_err("too many file under this dir!\n",__LINE__);
    }

    int i,j,len=strlen(path);

    dir=opendir(path);

    for(int i=0;i<count;i++)
    {
        ptr=readdir(dir);
        if(ptr==NULL) my_err("readdir",__LINE__);
        
        strncpy(filename[i],path,len);
        filename[i][len]='\0';  //因为strcat的实现需要最后一位是‘\0’
        strcat(filename[i],ptr->d_name);
        filename[i][len+strlen(ptr->d_name)]='\0';
        display(flag_param,filename[i]);
    }

    closedir(dir);
    if(flag_param & PARAM_L ==0)  //没有l的时候打印一个换行符
    putchar('\n');
}

int main(int argc ,char ** argv)
{
    int i=0,j=0,k=0,num=0;
    char path[_PC_PATH_MAX+1];
    char param[40];//保存命令行参数
    int flag_param=0;
    struct stat buf;

    for(i=0;i<argc;i++)
    {
        if(argv[i][0]=='-')
        {
            for(k=1;k<strlen(argv[i]);k++,j++)   //j是出现的参数总数
            param[j]=argv[i][k];  //保存命令行参数
        num++;  //保存 ’-‘ 的数量
        }
    }
    for(i=0;i<j;i++)
    {
        if(param[i]=='a')
        {
            flag_param|=PARAM_A;
        }else if(param[i]=='l')
        {
            flag_param|=PARAM_L;
        }else
        {
            printf("is a invaild param!\n");
            exit(1);
        }
    }

    param[j]='\0';
    if(num+1==argc)
    {
        strcpy(path,"./");  //没有参数的话默认为当前目录
        path[2]='\0';
        display_dir(flag_param,path);
        return 0;
    }
    i=1;
    do{
        //if(i==argc-1) return 0;; //防止无参数时的段错误
        if(argv[i][0]=='-') 
        {
            i++;
            continue;
        }else
        {
            //printf("%s\n",path);
            strcpy(path,argv[i]);
            if(stat(path,&buf)==-1)
            {
                my_err("stat",__LINE__);
            }
            if(S_ISDIR(buf.st_mode))
            {
                if(path[strlen(argv[i])-1]!='/')
                {
                    path[strlen(argv[i])]='/';
                    path[strlen(argv[i])+1]='\0';//保证字符串末尾为空零 方便进行字符串操作
                }else
                {
                    path[strlen(argv[i])]='\0';
                }
                display_dir(flag_param,path);
            }else
            {
                display(flag_param,path);//参数为一个文件
            }
            i++;
        }
    }while(i<argc);
    return 0;
}
