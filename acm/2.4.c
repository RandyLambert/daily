#include<stdio.h>
int n,flag = 0,xxx = 0,mi = 9999999;
int a[100004],b[100004];
void dfs(int step){
    if(step == n+1){
        int x = a[2]-a[1];
        int xx = 1;
        for(int i = 3;i<=n;i++){
            if(x == a[i] - a[i-1]){
                xx++;
            }
        }
        if(xx == n-1){
            flag = 1;
            for(int i = 1;i <= n;i++){
                if(b[i] == 1){
                    xxx++;
                }
            }
        }

            if(mi > xxx){
                mi = xxx;
            }
            xxx = 0;

    }
    else{
        dfs(step+1);

        a[step] = a[step] - 1;
        b[step] = 1;
        dfs(step+1);
        a[step] = a[step] + 1;
        b[step] = 0;

        a[step] = a[step] + 1;
        b[step] = 1;
        dfs(step+1);
        a[step] = a[step] - 1;
        b[step] = 0;

    }
}
int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }

    dfs(1);
    if(mi!=9999999)
        printf("%d",mi);
    else
        printf("%d",-1);
    return 0;
}
