/* #include<stdio.h> */ 
/* #include<stdlib.h> */
/* int m,n; */
/* int main() { */
/*     double max = 0; */
/*     scanf("%d %d",&m,&n); */
/*     while(m <= n){ */
/*         max += m*m; */
/*         max += 1.0/m; */
/*         m++; */
/*     } */
/*     printf("sum = %.6lf",max); */
/* } */
#include<stdio.h>
#include<math.h>                                                                                                                                                                                                       
#include<stdbool.h>
bool  sushu(int i) {
    int j;
    int f = 0;
    if(i == 2)
        return 1;
    for(j = 2;j < sqrt(i)+1;j++){
        if(i%j == 0){
            f = 1;
            break;
        }
    }
    if(f == 0)
        return 1;
    else
        return 0;
}                                                                                                                                                                                                  
int main(){
    int n,t;
    int i = 1;
    scanf("%d",&n);
    while(i < n){
        i++;
        if(sushu(i)){
            t = n-i;
            if(sushu(t)){
                printf( "%d = %d + %d",n,i,t);
                break;
            }
        }
    }
}

