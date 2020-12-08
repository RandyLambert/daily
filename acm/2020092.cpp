#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,t,xl,yd,xr,yu;
    int ansdou = 0,ansjing = 0;
    cin>>n>>k>>t>>xl>>yd>>xr>>yu;
    for(int i = 0;i < n;i++) {
        bool dou = false,jing = false;
        int x,y,cnt = 0;
        for(int j = 0;j < t;j++) {
            cin>>x>>y;
            if( x >= xl && x <= xr && y <= yu && y >= yd){
                jing = true;
                cnt++;
            } else {
                cnt = 0;
            }

            if(cnt == k){
                dou = true;
            }
        }
        if(jing == true){
            ansjing++;
        }
        if(dou == true){
            ansdou++;
        }
    }

    cout<<ansjing<<endl;
    cout<<ansdou<<endl;

    return 0;
}
