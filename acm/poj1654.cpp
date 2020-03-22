#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int dx[10] = { 0,-1,0,1,-1,0,1,-1,0,1 };
int dy[10] = { 0,-1,-1,-1,0,0,0,1,1,1 };
string s;
int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        long long ans=0, px=0, py=0, nx=0, ny=0;
        int len=s.size(); 
        for(int i=0; i<len-1; i++)
        {
            int t0=s[i]-'0';
            px=nx+dx[t0];
            py=ny+dy[t0];
            ans+=(nx*py - ny*px);
            nx=px;
            ny=py;
        }
        if(ans<0)
            ans=-ans;
        cout<<ans/2;
        if(ans%2)
            cout<<".5";
        cout<<endl;
    }
    return 0;
}
