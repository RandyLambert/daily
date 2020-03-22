#include <stdio.h>
int main(){
    int x,ans = 0,flag=0,i,j;
    scanf("%d",&x);
    for(i = 1;i < 9999;i++){
        ans = i;
        for(j = i+1;j < 10000;j++){
            ans = ans + j;
            if(ans == x){
                flag = 1;
                break;
            }
            if(ans > x){
                break;
            }
        }
        if(flag == 1){
            break;
        }
    }
    printf("%d %d\n",i,j);
    return 0;
}

