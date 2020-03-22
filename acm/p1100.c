#include<stdio.h>
int main(){
//位运算直接操作
    unsigned long long x = 0,y = 0,z = 0;
    y = (x&0x0000ffff)<<16; //太大了月节了
    z = (x&0xffff0000)>>16;
    scanf("%llu",&x);
    printf("%llu\n",(((x&0x0000ffff)<<16) +  ((x&0xffff0000)>>16)));
    printf("%llu\n",x);
    printf("%llu",z);


    return 0;
}
