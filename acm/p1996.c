#include<stdio.h>
int main(){
    int n,m,x = 0,f = 0;
    int a[102] = {0};
    scanf("%d%d",&n,&m);
    int flag = n;
    if(flag != 0){
    for(int i = 1;i <= n;i++){
        a[i] = i;
    }   
    while(1){
        while(f != m){ 
            if(a[x+1] == 0){ 
                x = (x+1)%(n+1);
            }
            else{
                x = (x+1)%(n+1);
                ++f;
            }
        }
        if(a[x]!=0){

            if(flag != 1)
                printf("%d ",a[x]);
            else
                printf("%d",a[x]);

        }
        flag--;
        a[x] = 0;
        f = 0;
        if(flag == 0){ 
            break;
        }
    }   
    }
    return 0;
} 
