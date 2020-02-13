#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <string.h>
int main(){

    char host[199] = {0};
    gethostname(host,sizeof(host));
    printf("%s\n",host);
    struct hostent *hp;
    if((hp = gethostbyname(host))==NULL){
        exit(0);
    }
    
    int i = 0;
    while(hp->h_addr_list[i]!=NULL){
        printf("%s\n",inet_ntoa(*(struct in_addr*)hp->h_addr_list[i]));
        i++;
    }
    memset(host,0,sizeof(host));
    inet_pton(AF_INET,"192.168.1.106",host);
    hp = gethostbyaddr(host,sizeof(AF_INET),AF_INET);
    
    printf("%s\n",hp->h_name);
    return 0;
}

