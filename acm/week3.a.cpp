#include<stdio.h>
#include<iostream>
using namespace std;
int text[100005],f[100005],mon[100005],high[100005];
int find(int x){
    if(x == f[x]){
        return x;
    }
    else{
        f[x] = find(f[x]);
        return f[x];
    }
}

int main(){
    int n,m,x,y;
    long long int sum = 0;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&mon[i]);
    }

    for(int i = 1;i <= n;i++){
        f[i] = i;
    }
    for(int i = 1;i <= m;i++){
        scanf("%d%d",&x,&y);
        int bootx = find(x);
        int booty = find(y);

        if(bootx != booty){
            mon[bootx] = min(mon[bootx],mon[booty]);
            f[booty] = f[bootx];
            mon[booty] = 0;
        }
    }
    for(int k = 1;k <= n;k++){
        sum = sum + mon[k];
    }
    printf("%lld\n",sum);

    
    return 0;
}
