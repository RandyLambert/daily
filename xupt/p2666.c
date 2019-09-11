#include<stdio.h>
#include<math.h>

int n;
int aa[102],bb[102];
int max;

void dfs(int sum,int step){
    if(sum == n){
        max++;
    }
    else  if(step == 4&&sum!=n)
        return;
    else if(sum > n)
        return;
    else{
        for(int i = 0;i <= sqrt(n);i++){
                sum = sum + aa[i];
                dfs(sum,step+1);
        }
    }
}
int main(){
    for(int i = 0;i <= 101;i++){
        aa[i] = i*i;
    }
    scanf("%d",&n);
    dfs(0,0);
    printf("%d",max);
    return 0;
}
