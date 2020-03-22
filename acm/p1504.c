#include<stdio.h>
int mm[101] = {-1};
int nn[1001];
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&nn[i]);
    }
    
    int k = 0,flag = 0,x = 0,sum = 0;
    while(x <= n){
        for(int i = 0;i < m;i++){
            if(mm[i] == nn[x]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            mm[k%m] = nn[x];
            k = k + 1;
            sum++;
        }
        x++;
        flag = 0;
    }
     printf("%d",sum);
    return 0;
}
