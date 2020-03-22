#include <bits/stdc++.h>
using namespace std;
map<string,int>q;
int f[20010];
int findf(int s){
    if(f[s] == s){
        return s;
    }
    else{
        return f[s] = findf(f[s]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    string s,p;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>s;
        q[s] = i;
        f[i] = i;
    }
    for(int i = 0;i < m;i++){
        cin>>s>>p;
        int fs = findf(q[s]);
        int fp = findf(q[p]);
        if(fs != fp){
            f[fs] = fp;
        }
    }

    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>s>>p;
        int fs = findf(q[s]);
        int fp = findf(q[p]);
        if(fs == fp){
            cout<<"Yes."<<"\n";
        }
        else{
            cout<<"No."<<"\n";
        }
        
    }

    return 0;
}

