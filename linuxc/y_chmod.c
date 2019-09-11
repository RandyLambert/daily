#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char ** argv){
    int mode;  //权限
    int mode_u; //所有者的权限
    int mode_g; //所属组的权限
    int mode_o; //其他用户的权限
    char * path;  
    if(argc < 3){
        printf("%s <mode num> <target file>\n",argv[0]);
        exit(0);
    }
    //获取命令行参数
    mode = atoi(argv[1]);
    if(mode > 777 || mode < 0){
        printf("mode num error!\n");
        exit(0);
    }
    printf("%d\n",mode);
    mode_u = mode/100;
    printf("%d\n",mode_u);
    mode_g  = (mode - (mode_u*100)) / 10;
    printf("%d\n",mode_g);
    mode_o = mode - (mode_u*100) - (mode_g*10);
    printf("%d\n",mode_o);
    mode = (mode_u * 8 * 8) + (mode_g * 8) + (mode_g * 8) + mode_o;
    path = argv[2];
    printf("%d\n",mode);


    if(chmod(path,mode)==-1){
        perror("chmod error\n");
        exit(1);
    }

    return 0;
}

