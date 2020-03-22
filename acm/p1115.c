#include<stdio.h>
int a,b;
int dong[200001];
int next[200001];
int x,sum = -999999;
int max(int a,int b){
    if(a < b) return b;
    else return a;
}
int main(){
    scanf("%d",&a);
    for(int i = 1;i <= a;i++){
        scanf("%d",&dong[i]);
        next[i] = max(next[i-1] + dong[i],dong[i]);
        sum = max(sum,next[i]);
    }
    printf("%d",sum);
    return 0;
}
