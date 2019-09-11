#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#define LNAME 9
#define PERMS 0666
#define DATAFILE "datafile"
#define USERS 10

typedef struct user{
    int uid;
    char login[LNAME+1];
}RECORD;

char *user_name[] = {"u1","u2","u3","u4","u5","u6","u7","u8","u9","admin"};

int main(){

    int fd;

    if((fd = open(DATAFILE,O_WRONLY|O_TRUNC|O_CREAT,PERMS))==-1){
       perror("cuowu\n");
       exit(1);
    }

    for(int i = 0;i < USERS;i++){
        RECORD temp;
        temp.uid = i;
        strcpy(temp.login,user_name[i]);
        /* lseek(fd,i*sizeof(RECORD),SEEK_SET); */
        write(fd,&temp,sizeof(RECORD));
    }

    lseek(fd,0L,SEEK_SET);


    
    return 0;
}

