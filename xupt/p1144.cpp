#include <bits/stdc++.h>
using namespace std;
vector<int>q[1000009];
int len[1000009];
int main(){
    int n,m,x,y;
    scanf("%d%d",n,m);
    for(int i = 1;i <= m;i++){
        scanf("%d%d",&x,&y);
        q[x].push_back(y);
        q[y].push_back(x);
        if(i<=n)
            len[i] = 199999999;
    }
    len[1] = 0;
    for(int i = )
    return 0;
}
