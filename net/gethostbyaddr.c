#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
 
int main(int argc, char **argv)
{
	char *ptr, **pptr;
	struct in_addr addr;
	struct hostent *phost;
	char str[32] = {0};

	ptr = argv[1];

	printf("ip:%s\n", ptr);
 
	if (inet_pton(AF_INET, ptr, &addr) <= 0) {
		printf("inet_pton error:%s\n", strerror(errno));
		return -1;
	}
 
	phost = gethostbyaddr((const char*)&addr, sizeof(addr), AF_INET);
    printf("%d",sizeof(addr));
	if (phost == NULL) {
		printf("gethostbyaddr error:%s\n", strerror(h_errno));
		return -1;
	}	
 
	printf("official hostname:%s\n", phost->h_name);   	//主机规范名
	
	return 0;
}

