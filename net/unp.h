#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <time.h>
#include <netinet/in.h>
#define MAXLEN 1024
int sockfd;
struct sockaddr_in servaddr;

void Time_Get();
void Read_Time(char recvline[]);
