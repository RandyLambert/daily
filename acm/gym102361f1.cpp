#include<iostream>
#include<vector>
#include<cstring>
#define MOD 998244353
#define LL long long
using namespace std;
LL qpow(LL base,int n){
    LL ans=1;
    while(n){
        if(n&1)ans=ans*base%MOD;
        base=base*base%MOD;
        n>>=1;
    }
    return ans;
}
int vis[300005];
//0代表没访问过 1代表访问过 2代表访问过且已作为环找到过
int depth[300005];
vector<int> edge[300005];
vector<int> cnt;
void dfs(int u,int fa,int dpt){
    int l=edge[u].size();
    depth[u]=dpt;
    for(int i=0;i<l;i++){
        int v=edge[u][i];
        if(v==fa || depth[v]>dpt)continue;
        //printf("u:%d %d v:%d %d\n",u,dpt,v,depth[v]);
        if(depth[v]>=0 && depth[v]<depth[u]){
            cnt.push_back(depth[u]-depth[v]+1);
            //printf("Bingo%d\n",dpt-depth[v]+1);
            //depth[u]=dpt;
        }
        else{
            //depth[u]=dpt;
            //vis[u]=1;
            dfs(v,u,dpt+1);
        }
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    } 
    memset(depth,-1,sizeof depth);

    for(int i=1;i<=n;i++){
        if(depth[i]==-1)
            dfs(i,-1,0);
    }
    int sz=cnt.size();
    long long ans=1;
    for(int i=0;i<sz;i++){
        printf("%d\n",cnt[i]);
        ans=ans*(qpow(2,cnt[i])-1)%MOD;
        m-=cnt[i];
    }
    ans=ans*qpow(2,m)%MOD;
    printf("%lld\n",ans);
    return 0;
}
