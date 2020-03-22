#include<stdio.h>
int main(){
    char a[3],b[3],c[5];
    int d[2],e[2],f[4];
    scanf("%s-%s-%s",a,b,c);
    for(int i = 0; i<2; i++){
        d[i] = a[i]-'0';
        e[i] = b[i]-'0';
    }
    for(int j = 0;j<4;j++)
        f[j] = c[j]-'0';
    
    return 0;
}
