#include <stdio.h>
#include <math.h>
int main(){
    int x = 12,z = 0;
    for(int i = 1;i <= sqrt(x);i++){
        if(x%i==0){
            z= z+i;
            z= z+(x/i);
        }
        printf("%d   ",z);
    }
    printf("%d",z);
    return 0;
}

