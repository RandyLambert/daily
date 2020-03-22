#include <bits/stdc++.h>
using namespace std;
int ans[210];
bool vis[210];
struct node
{
    int b,step;
};
int main(){
    
    queue<node>q;
    int n,a,b,flag = 0;
    cin>>n>>a>>b;
    for(int i = 1;i <= n;i++){
        cin>>ans[i];
    }

    node start;
    start.b = a;
    start.step = 0;

    q.push(start);

    while(!q.empty())
    {
        node tp = q.front();
        q.pop();

        if(tp.b == b)
        {
            flag = 1;
            cout<<tp.step<<"\n";
        }
        else{
            node nw;
            if(tp.b + ans[tp.b]<=n && vis[tp.b + ans[tp.b]]==0){
                nw.b = tp.b+ans[tp.b];
                nw.step = tp.step+1;
                vis[tp.b + ans[tp.b]]=1;
                q.push(nw);

            }
            if(tp.b - ans[tp.b] >0 && vis[tp.b - ans[tp.b]]==0){
                nw.b = tp.b - ans[tp.b];
                nw.step = tp.step+1;
                vis[tp.b - ans[tp.b]]=1;
                q.push(nw);
            }
        }
    }
    if(flag == 0)
        cout<<-1<<"\n";
    return 0;
}

