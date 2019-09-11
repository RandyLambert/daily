#include <bits/stdc++.h>
using namespace std;

int f[20005];
int n,m;
struct cun{
    int cun1,cun2,tim;
}hh[20005];

bool cmp(cun a,cun b){
    return a.tim < b.tim;
}

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
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        f[i] = i;
    }
    
    for(int i = 1;i <= m;i++){
        scanf("%d%d%d",&hh[i].cun1,&hh[i].cun2,&hh[i].tim);
    }

    sort(hh+1,hh+m+1,cmp);

    int num = 0,t = 0;
    for(int i=1;i<=m;i++)
    {
        int u=find(hh[i].cun1),v=find(hh[i].cun2);
        if(u!=v)
        {
            f[u]=v;
            num++;
            t=max(t,hh[i].tim);
        }
    }
    if(num>=n-1)cout<<t<<endl;
    else cout<<-1<<endl;
    return 0;
}
