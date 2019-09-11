#include<stdio.h>
int n;
int a[1005],b[1005],c[1005];
int main(){
    scanf("%d",&n);
    int temp,t;
    double mix = 0,mx = 0;
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
        c[i] = i;
    }

    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            if(a[i] > a[j]){
                t = a[i];
                a[i] = a[j];
                a[j] = t;

                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
    b[0] = a[0]; 
    for(int i = 1;i < n;i++){
        b[i] = a[i];
        a[i] =  a[i] + a[i-1];
    }
    for(int i = 0;i < n;i++){
        a[i] = a[i] - b[i];
        mx = a[i] + mx;
    }
    mix = mx/n;
    for(int i = 0;i < n;i++)
        printf("%d ",c[i]+1);
    putchar('\n');
    printf("%.2lf",mix);
    return 0;
}
