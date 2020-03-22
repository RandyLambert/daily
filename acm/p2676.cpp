#include<stdio.h>
void paixu(int a[],int l){
    int i,j,t;
    for(i = 0;i < l;i ++){
        for(j = 0;j < l - 1 - j;j++){
            if(a[j] > a[j+1]){
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
}
void paixu2(int a[],int l){
    int i,j,t;
    for(i = 0;i < l;i++){
        for(j = i+1;j < l;j ++){
            if(a[i] > a[j]){
                t = a[i];
                a[i] = a[j];
                a[j] = t;

            }
        }
    }
}
int main(){
    int n,m,a[1000],b[1000],p[1000] = {0},c,d;
    scanf("%d%d",&n,&m);
    c = n;
    int i,j;
    for(i = 0;i < n;i++){
      scanf("%d",&a[i]);
    }
    for(j = 0;j < m;j++){
        scanf("%d",&b[j]);
    }
    paixu(a,n);
    paixu2(b,m);
    
    for(i = 0;i < n;i++){
        for(j = 0;j < m;j ++){
            if(!p[j] && b[j] >= a[i]){
                d = d + b[j];
                p[j] = 1;
                n--;
                break;
            }
        }
    }
    if(n == 0){
        printf("%d",d);
    }
    else{
        printf("you died!");
    }

    return 0;
}
