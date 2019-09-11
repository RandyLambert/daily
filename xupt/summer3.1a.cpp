#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long llu;
typedef unsigned int uint;

struct node{
    llu s[2][2]; 
};

node mut(node a,node b){

    node c;
    memset(c.s,0,sizeof(c.s));
    for(int i = 0;i < 2;i++)
        for(int j = 0;j < 2;j++)
            for(int k = 0;k < 2;k++)
                c.s[i][j] = c.s[i][j]+ b.s[k][j]*a.s[i][k];
    return c;
                
}

node quick(llu n,node p){

    node q;
    memset(q.s,0,sizeof(q.s));
    
    q.s[0][1] = q.s[1][0] = 0;
    q.s[1][1] = q.s[0][0] = 1;

    while(n){
        if(n&1)
            q = mut(p,q);
        p = mut(p,p);
        n = n/2;
    }

    return q;
}
int main(){
    
    llu t,cnt = 1;
    llu x,y,z;
    cin>>t;
    while(t--){
        cin>>x>>y>>z;
        

        if(z == 1){
            cout<<"Case "<<cnt++<<": "<<x<<"\n";
            continue;    
        }
        else if(z == 2){
            cout<<"Case "<<cnt++<<": "<<x*x-2*y<<"\n";
            continue;    
            
        }
        else if(z == 0){
            cout<<"Case "<<cnt++<<": "<<2<<"\n";
            continue;    
        }
        else{
            node a1,b1;
            a1.s[0][0] = x;
            a1.s[1][0] = x*x-2*y;
            a1.s[1][1] = 0;
            a1.s[0][1] = 0;

            b1.s[0][0] = x;
            b1.s[1][0] = -1*y;
            b1.s[0][1] = 1;
            b1.s[1][1] = 0;

            node ans = quick(z-2,b1);

            cout<<"Case "<<cnt++<<": "<<a1.s[1][0]*ans.s[0][0] + a1.s[0][0]*ans.s[1][0]<<"\n";
        }
    }
    return 0;
}
