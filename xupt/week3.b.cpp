#include <bits/stdc++.h>
using namespace std;
int n,m,a[505],b[505],mp[505][505];
void tuo(){
    queue <int> q;
    int l = 0;
    while(!q.empty()) q.pop();
    for(int i = 1;i <= n;i++){
        if(!a[i]){
            q.push(i);
        }
    }
    int sum = q.front();
       while(!q.empty())
    {
        b[l++]=sum;
        q.pop();
        for(int i=1;i<=n;i++)
        if(mp[sum][i])
        {
            a[i]--;
            if(!a[i])
            q.push(i);
        }
        sum=q.front();
    }
    for(int i=0;i<n;i++)
    printf("%d ",b[i]);
    printf("\n");
}
int main(){
    while(scanf("%d%d",&n,&m)&&n!=0){
        memset(mp,0,sizeof(mp));
        memset(a,0,sizeof(a));

         for(int i=0;i<m;i++){
            int h,r;
            scanf("%d%d",&h,&r);
            if(!mp[h][r]){
                mp[h][r]=1;
                a[r]++;
            }
        }
         tuo();
    }
    return 0;
}
