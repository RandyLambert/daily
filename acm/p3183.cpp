#include <bits/stdc++.h>
using namespace std;
queue <int> q;
vector<int> qq[100010];
int f[100010],out_[100010],lian[100010];
int main(){
    int n,m,a,b,ans=0;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m;i++){
        scanf("%d%d",&a,&b);
        qq[a].push_back(b);
        f[b]++;
        out_[a]++;
    }
    for(int i = 1;i <= n;i++){
         if(f[i]==0) q.push(i),lian[i]=1;
    }
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i = 0;i < qq[temp].size();i++){
            --f[qq[temp][i]];
            lian[qq[temp][i]]+=lian[temp];
            if(!f[qq[temp][i]] && !out_[qq[temp][i]])
                ans+=lian[qq[temp][i]];
            else if(!f[qq[temp][i]])
                q.push(qq[temp][i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
