#include <bits/stdc++.h>
using namespace std;
vector<int>a[105];
queue<int>q;
int dp[105];
int f[105];
int main(){
    int n,m,x,y,len = 1;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m;i++){
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        f[y]++;
    }
    for(int i = 1;i <= m;i++){
        if(f[i]==0){
            q.push(i);
            dp[i] = 1;
        }
    }
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i = 0;i < a[temp].size();i++){
            if(f[a[temp][i]]>= 1) f[a[temp][i]]--;
            if(f[a[temp][i]]==0){
                q.push(a[temp][i]);
                dp[a[temp][i]] = dp[temp]+1;
            }
        }
    }
    printf("%d",*max_element(dp,dp+n+1));

    return 0;
}

