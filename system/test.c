#include <stdio.h>
int n = 0;
static inline int dfs(int a){
    if(a == 10000){
        return a;
    }
    else{
        a++;
        return dfs(a);
    }
}
int main(){
    static int xx;

    printf("%d\n",dfs(0));
    
    return 0;
}
