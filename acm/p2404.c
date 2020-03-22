#include<stdio.h>
int n,p[11]={1},m;

void print (int a){
    for(int i = 1;i<a;i++){
        printf("%d+",p[i]);
    }
    printf("%d\n",p[a]);
}

void dfs(int a){
     for(int i=p[a-1]; i<=m; i++){//回溯后跳出分支

         if(i==n){
            continue;
         } //防止最后一行输出n
         
        p[a]=i;
        m=m-i;

        if(m==0){
           print(a);//m减完时，该方案已排列完毕，进行输出
        }
        else{
            dfs(a+1);//否则继续搜索

        }
        m=m+i;//回溯
    }
}
int main(){
    scanf("%d",&n);
    m = n;
    dfs(1);
    return 0;
}
