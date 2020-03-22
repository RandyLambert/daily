#include <stdio.h>
int max(int a,int b){
    if(a>b) return a;
    else return b;
}
int min(int a,int b){
    if(a>b) return b;
    else return a;
}
int gcd(int a,int b){
    if(a-b!=0)
        gcd(max(a-b,b),min(a-b,b));
    else 
        return a;
}

int main(){
    int a,b;
    scanf("%d,%d",&a,&b);
    int a1 = max(a,b);
    int b1 = min(a,b);
    printf("gcd=%d\n",gcd(a1,b1));
    return 0;
}

