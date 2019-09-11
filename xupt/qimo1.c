#include <stdio.h>
int main(){
    
    int a[3][4],max = 0,ans = 0,cnt = 0;
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 4;j++){
            scanf("%d",&a[i][j]);
            max = max+a[i][j];
        }
    double pi = (double)(max)/12;
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 4;j++){
            if(a[i][j]>=pi){
                cnt++;
                ans = ans + a[i][j];
            }
        }
    printf("s=%d,n=%d\n",ans,cnt);


    return 0;
}

