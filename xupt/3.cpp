#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll da[100000],ru[100000];
vector<ll>mp[10000];
const int maxn = 100000;
priority_queue <ll,vector<ll>,greater<ll>> q;
int main(){

    ll cnt1 = 0,cnt = 0,num = 0;

        string a1;
        while(getline(cin,a1))
        {
            if(a1.size()==0){
                break;
            }

            int x1,pos = 0,m,n;
            
            stringstream st;
            st<<a1;
            while(st>>x1){

                if(pos == 0){
                    n = x1;
                    pos++;
                }
                
                else if(pos != 0)
                {
                    m = x1;
                    mp[m].push_back(n);
                    ru[n]++;
                    pos++;
                }
                /* cout<<n<<"\n"; */
            }
            num++;
        }

        /* for(int i = 1;i <= num;i++) */
        /* { */
        /*     cout<<ru[i]<<"\n"; */
        /* } */

        for(int i = 1;i <= num;i++)
        {
            if(!ru[i])
                q.push(i);
        }

        while(!q.empty())
        {
            int y = q.top();
            da[cnt++] = y;
            q.pop();
            cnt1++;

            ll z = mp[y].size();

            for(int i = 0;i < z;i++){
                ll tmp = mp[y][i];
                if(ru[tmp] > 0){
                    ru[tmp]--;
                    if(ru[tmp] == 0){
                        q.push(tmp);
                    }
                }
            }
        }
        if(cnt1<num){
            cout<<-1;
        }
        else{
            for(int i = 0;i < num;i++){
                cout<<da[i]<<" ";
            }
        }
    return 0;
}
