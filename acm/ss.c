#include<stdio.h> 
int a[10000],b[10000],p[10000] = {0};
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
    int n,m,c,d = 0;
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
                c--;
                break;
            }
        }
    }
    if(c == 0){
        printf("%d",d);
    }
    else{
        printf("you died!");
    }

    return 0;
} 
