#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[505];
vector<int>w[505];
priority_queue<int,vector<int>,greater<int> >q;
int main(){
    
    while(scanf("%d%d",&n,&m)==2)
    {
        int cc = 0;
        memset(a,0,sizeof(a));
        while(!q.empty()) q.pop();
        for(int i = 0;i <= m;i++) w[i].clear();
        for(int i = 1;i <= m;i++)
        {
            int a1,a2;
            scanf("%d%d",&a1,&a2);
            a[a2]++;
            w[a1].push_back(a2);
        }
        for(int i = 1;i <= n;i++)
        {
            if(a[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int temp = q.top();
            if(cc==0){
                printf("%d",temp);
                cc++;
            }
            else{
                printf(" %d",temp);
            }
            q.pop();
            for(int i = 0;i < w[temp].size();i++)
            {
                a[w[temp][i]]--;
                if(a[w[temp][i]]==0) 
                {
                    q.push(w[temp][i]);
                }
            }
        }
        putchar('\n');
    }
    return 0;
}
