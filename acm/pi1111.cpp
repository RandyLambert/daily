#include<stdio.h>
#include<string.h>
int f[1005],cun1[100005],cun2[100005],tim[100005];
int n,m;
int cu = 0;
int find(int x){
    if(x == f[x]){
        return x;
    }
    else{
        f[x] = find(f[x]);
        return f[x];
    }
}

void gudge(int x,int y){
    int xx = find(x);
    int yy = find(y);
    if(xx != yy){
        f[yy] = xx;
    }
}

int panduan(int mid){
    cu = 0;
    for(int i = 1;i <= m;i++){
        if(tim[i] <= mid){
            gudge(cun1[i],cun2[i]);
        }
    }
    for(int i = 1;i <= n;i++){
        if(f[i] == i){
            cu++;
        }
    }
    for(int i = 1;i <= n;i++){
        f[i] = i;
    }

    if(cu == 1){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int max = -1;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        f[i] = i;
    }
    
    for(int i = 1;i <= m;i++){
        scanf("%d%d%d",&cun1[i],&cun2[i],&tim[i]);
        if(tim[i] > max){
            max = tim[i];
        }
    }

    int r = max;
    int l = 1;
    while(l<=r){
        int mid = (l+r)/2;
        if(panduan(mid)){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    if(cu==1)
        printf("%d",r+1);
    else
        printf("-1");
    return 0;
}
