#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int n,xx = 0;
int zuo[28],shang[28];
int you[28];
int step[14];
bool panduan(int x,int i){
        if(you[x+i]==0&&zuo[n-i+x]==0&&shang[i]==0)
            return 1;
        else
            return 0;
}
void dfs(int x){
    if(x == n+1){
        if(xx<3){
            for(int i = 1;i <= n;i++){
                printf("%d ",step[i]);
            }
        putchar('\n');
        }
        xx++;
    }
    else{
        for(int i = 1;i <= n;i++){
            if(panduan(x,i)){
                step[x] = i;
                shang[i]=1;
                you[x+i]=1;
                zuo[n-i+x]=1;

                dfs(x+1);
                
                shang[i]=0;
                you[x+i]=0;
                zuo[n-i+x]=0;

            }
        }
    }    
}
int main(){
    scanf("%d",&n);
    dfs(1);
    printf("%d\n",xx);
    return 0;
}
