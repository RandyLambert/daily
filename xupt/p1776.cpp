#include <bits/stdc++.h>
using namespace std;
int w[1000010],v[1000010],x[1000010];
int main(){
    int n,m,cnt = 0;
    int a,b,c;
    cin>>n>>m;

    for(int i = 0;i < n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        for(int j = 1;j<=c;j=j<<1)
        {
            v[++cnt] = j*a;
            w[cnt] = j*b;
            c=c-j;
        }
        if(c!=0) {
            v[++cnt] = c*a; 
            w[cnt] = b*c;
        }
    }

    for(int i = 1;i <= cnt;i++){
        for(int j = m;j >= w[i];j--){
            x[j] = max(x[j],x[j-w[i]] + v[i]);
        }
    }
    cout<<x[m];
    return 0;
}
