#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,a = 150,i = 0;
    scanf("%d",&n);
        for(int j = 1;j <= 30;j++){
            for(int k = 1;k <= 75;k++){
                for(int x = 1;x <= 150;x++){
                    if(j*5+k*2+x*1==a&&j+k+x==100){
                        i++;
                        printf("%d %d %d\n",j,k,x);
                        if(i==n)
                            exit(0);
                    }
                }
            }
        }
    return 0;
}

