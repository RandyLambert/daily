#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(int argc,char **argv){
    
    struct stat buf;
    if(argc!=2){
        printf("usage:my_stat <sdas>\n");
        exit(0);
    }

    //获取文件属性
    if(stat(argv[1],&buf) == -1){
        perror("stat:");
        exit(0);
    }

    //打印文件属性
    printf("device is:%d\n",buf.st_dev);
    printf("inode is:%d\n",buf.st_ino);
    printf("mode is:%o\n",buf.st_mode);
    printf("num of hard link is:%d\n",buf.st_nlink);
    printf("user id of owner is:%d\n",buf.st_uid);
    printf("group id of owner is:%d\n",buf.st_gid);
    printf("device type(if inode device) is:%d\n",buf.st_rdev);
    
    
    printf("totoal size (bytes )is:%d\n",buf.st_size);
    printf("brocksize of filesystem I/O is:%d\n",buf.st_blksize);
    printf("number of blocks allocated  is:%d\n",buf.st_blocks);


    printf("time of last access is:%s\n",ctime(&buf.st_atime));
    printf("time of last modification is:%s\n",ctime(&buf.st_mtime));
    printf("time of last change is:%s\n",ctime(&buf.st_ctime));
    return 0;
}

