#include <bits/stdc++.h>
using namespace std;
int f[10005];
inline int find(int x){
    while(x!=f[x])
        x = f[x] = f[f[x]];
    return x;
}
int main(){
    int n,m,a,b,c;
    cin>>n>>m;
    for(int i = 0;i <= n;i++){
        f[i] = i;
    }
    for(int i = 0;i < m;i++){
        scanf("%d%d%d",&a,&b,&c);
        if(a == 1){
            int fx = find(b);
            int fy = find(c);
            if(fx!=fy){
                f[fy] = f[fx];
            }
        }
        else if(a == 2){
            int fx = find(b);
            int fy = find(c);
            if(fx == fy){
                printf("Y\n");
            }
            else{
                printf("N\n");
            }
        }
    }
    return 0;
}
