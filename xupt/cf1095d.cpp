#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int mp[2][maxn];
int ans[maxn],n;
int vis[maxn];
void dfs(int x,int step){
    
    while(step <= n){
        int xx = mp[0][x];
        int yy = mp[1][x];
        if(mp[0][xx] == yy||mp[1][xx] == yy){
            if(vis[xx] == 0){
                ans[step+1] = xx;
                step+=1;
                x=xx;
                vis[xx] = 1; 
            }
            else{
                ans[step+1] = yy;
                step+=1;
                x=yy;
                vis[yy] = 1;
            }
        }
        else{
            if(vis[yy] == 0){
                ans[step+1] = yy;
                step+=1;
                x=yy;
                vis[yy] = 1;
            }
            else{
                ans[step+1] = xx;
                step+=1;
                x=xx;
                vis[xx] = 1;
            }

        }
    }
        
}
int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d%d",&mp[0][i],&mp[1][i]);
    }
    ans[1] = 1;
    vis[1] = 1;
    dfs(1,1);
    for(int i = 1;i <= n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
