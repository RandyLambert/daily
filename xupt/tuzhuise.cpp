#include <bits/stdc++.h>
using namespace std;
vector <int> q[100];
int color[100],v,e,s,h;
bool dfs(int x,int c){
    color[x] = c;
    for(int i = 0;i < q[c].size();i++){
        if(color[q[c][i]]==c)
            return 0;
        if(color[q[c][i]]==0&&dfs(q[c][i],-c)==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    cin>>v>>e;
    for(int i = 0;i < e;i++)
    {
        cin>>s>>e;
        q[s].push_back(e);
        q[e].push_back(s);
    }

    for(int i = 0;i < v;i++)
    {
        if(color[i] ==0){
            if(dfs(i,1)==0){
                printf("no");
            }
        }
    }
    printf("yes");
    return 0;
}
