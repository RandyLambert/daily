#include<bits/stdc++.h>
using namespace std;
#define maxn 2000010
struct node{
    int w;
    int pos;
}A[maxn];
deque<node> Q;
int ans[maxn]; 
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&A[i].w);
        A[i].pos = i - 1;
    }
    for(int i = 1;i < n;i++)
    {
        while(!Q.empty()&&Q.back().w >= A[i].w)
            Q.pop_back();
        Q.push_back(A[i]);
        while(!Q.empty()&&Q.front().pos < i - m)
            Q.pop_front();
        ans[i] = Q.front().w;
    }
    printf("0\n");
    for(int i = 1;i < n;i++)
        printf("%d\n",ans[i]);  
}
