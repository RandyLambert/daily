#include<stdio.h>

int kai[8] = {1,3,0,4,3,5,6,8};
int jie[8] = {4,5,6,7,8,9,10,11};
int jia[8] = {5,1,8,4,6,3,2,4};
int zong = 0;
void dp(int shi,int i,int js){
    if(shi == 0){
        if(zong < i)
            zong = i;
    }
    else{
        if(kai[i] <= jie[i]){
            dp(shi-1,);
            dp(shi-1,)

        }
        if(kai[i] > jie[i]){
            dp(shi-1,);
        }
    }
}
int main(){
    
    return 0;
}
