#include<stdio.h>
int main(){
    int a,c,b = 0;
    long long int bi = 0;
    scanf("%d",&a);

    c = a;

    for(int j = 1;j<= a;j++){
        if(c >= j){
            c = c - j;
            b++;
        }
        else{
            break;
        }
    }

    for(int i = 1;i <= b;i++){
        bi = i*i + bi;
    }
    bi = bi + (b + 1)*c;
    printf("%lld",bi);
    return 0;
}
