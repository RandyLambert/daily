#include <bits/stdc++.h>
using namespace std;
vector<int>q[100010];
int du[100010],dp[100010],cun[100010];
queue <int> qq;
int main(){
    int n,m,x,y,cnt = 1;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m;i++){
        scanf("%d%d",&x,&y);
        q[x].push_back(y);
        du[y]++;
    }
    for(int i = 1;i <= n;i++){
        if(du[i] == 0){
            qq.push(i);
            cun[cnt++] = i;
        }
    }
    while(!qq.empty()){
        int temp = qq.front();
        qq.pop();
        for(int i = 0;i < q[temp].size();i++){
            if(du[q[temp][i]]>=1){
                du[q[temp][i]]--;
                if(du[q[temp][i]]==0){
                    qq.push(q[temp][i]);
                    cun[cnt++] = q[temp][i];
                }
            }
        }
    }
    for(int i = 1;i <= n;i++){
        dp[i] = 1;
    }
    for(int i = 1;i <= n;i++){
        int xx = cun[i];
        for(int j = 0;j < q[xx].size();j++){
            dp[q[xx][j]] = max(dp[xx]+1,dp[q[xx][j]]);
        }
    }
    for(int i = 1;i <= n;i++){
        printf("%d\n",dp[i]);
    }
    return 0;
}
