#include <stdio.h>
static inline int dfs(int a){
    if(a == 100000000){
        return a;
    }
    else{
        a++;
        return dfs(a);
    }
}
int main(){

    printf("%d\n",dfs(0));
    
    return 0;
}
