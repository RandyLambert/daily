#include <bits/stdc++.h>
using namespace std;
int n,f[200100];
vector<int>q[200100];
void dfs(int step,int pre)
{
    int cnt = 1;
    for(int i = 0;i < q[step].size();i++)
        if(q[step][i] != pre)
        {
            while(cnt == f[step] || cnt == f[pre])
                cnt++;
            f[q[step][i]] = cnt++;
        }
    for(int i = 0;i < q[step].size();i++)
        if(q[step][i] != pre)
            dfs(q[step][i],step);
}
int main(){
    scanf("%d",&n);
    for(int i = 0;i < n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        q[x].push_back(y);
        q[y].push_back(x);
    }
    f[1] = 1;
    dfs(1,0);
    printf("%d\n",*max_element(f+1,f+n+1));
    for(int i = 1;i <= n;i++)
    {
        printf("%d ",f[i]);
    }
    putchar('\n');
    return 0;
}
