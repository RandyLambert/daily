#include<stdio.h>
int main(){
    int n,m,s=0;
    scanf("%d%d",&n,&m);
    int visit[200] = {0};
        for(int k = 0;k<n;k++){
            for(int j = 0;j < m;j++){
                if(++s>n){
                    s = 1;
                }
                if(visit[s]){
                    j--;
                }
            }
            printf("%d ",s);
        }

    return 0;
}
