#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int aa[10004];
int main(){
    int a,b,n = 1,flag = 0,h = 0;
    
    while(1){
        scanf("%d",&a);
        if(a==0){
            break;
        }
        scanf("%d",&b);
        while(scanf("%d",&n)){
            h++;
            if(h<b*2){
                aa[n]++;
            }
            else{
                aa[n]++;
                for(int i = 1;i <= a;i++){
                    if(aa[i]%2!=0||!aa[i])
                        flag = 1;
                }
                if(flag == 1){
                    printf("0\n");
                }
                else{
                    printf("1\n");
                }
                h = 0;
                flag = 0;
                n = 1;
            memset(aa,0,sizeof(aa));
            break;
            }
        }
    }
    return 0;
}
