#include<stdio.h>
int sum[5001];
int a[5001];
int b[5001];
inline void add(){
    int flag = 0;
    for(int i = 0;i < 5001;i++){
        if(flag == 1){
            sum[i] = 1 + b[i] + a[i];
            flag = 0;
        }
        else{
            sum[i] = b[i] + a[i];
        }
        if(sum[i]>=10){
            flag = 1;
            sum[i] = sum[i]-10;
        }
    }

    for(int i = 0;i < 5001;i++){
        a[i] = b[i];
        b[i] = sum[i];
    }
}
int main(){
    int n;
    a[0] = 1,b[0] = 1;
    scanf("%d",&n);
    if(n == 1){
        printf("1\n");
    }
    else if(n == 0){
        printf("0\n");

    }
    else{
        for(int i = 0;i < n-1;i++){
            add();
        }

        int hh = 5001;
        while(sum[hh] == 0){
            hh--;
        }
        for(int i = hh;i >= 0 ;i--)
            printf("%d",sum[i]);
    }
    return 0;
}
