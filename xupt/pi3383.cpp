#include<cstring>
#include<cmath>
#include<stdio.h>
bool p[1000011];
int qian[1000011];
int num = 0;
int main(){
    int n,m;
    memset(p,1,sizeof(p));
    p[0] = p[1] = 0;
    for(int i = 2;i <= 1000010;i++){
        if(p[i]){
            qian[num++]=i;
        }
        for(int j = 0;j <num&&i*qian[j] < 1000010;j++){
            p[i*qian[j]] = 0;
            if(!(i*qian[j])) break;
        }
    }
    int xxx;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m;i++){
        scanf("%d",&xxx);
        if(p[xxx]==1){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}
