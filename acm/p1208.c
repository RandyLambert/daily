#include<stdio.h>
int n,m,pi[5005],ai[5005],mon = 0;
int main(){
    scanf("%d%d",&n,&m);
    int t,temp;
    for(int i = 0;i < m;i++){
        scanf("%d%d",&pi[i],&ai[i]);
    }

    for(int i = 0;i < m;i++){
        for(int j = i + 1;j < m;j++){
            if(pi[i]>pi[j]){
                temp = pi[i];
                pi[i] = pi[j];
                pi[j] = temp;

                t = ai[i];
                ai[i] = ai[j];
                ai[j] = t;
            }
        }
    }
    for(int i = 0;i < m;i++){
        if(n>ai[i]){
            n = n - ai[i];
            mon = pi[i]*ai[i] + mon;
        }
        else{
            mon = n*pi[i]+mon;
            break;
        }
    }
        printf("%d",mon);
    return 0;
}
