#include <bits/stdc++.h>
using namespace std;
queue<int>q;
int mp[105][105][105];
int dx[3];
struct node{
    int x[3];
    int len;
}
int main(){
    int s,n,m;
    while(~scanf("%d%d%d",&s,&n,&m)){
        if(s%2==1){
            printf("NO\n");
        }
        else
        {
            dx[0] = s,dx[1] = n,dx[2] = m;
            memset(mp,0,sizeof(mp));
            q.push(s);
            while(!q.empty())
            {
                    q.pop();
            }
            node start;
            start.x[0] = s;
            start.x[1] = 0;
            start.x[2] = 0;

            while(!q.empty()){
                node p = q.pop();
                if((p.x[0]==p.x[1]&&p.x[1]==xx)||(p.x[0]==p.x[2]&&p.x[0]==xx)||(p.x[1]==p.x[2]&&p.x[1]==xx))
                {
                    printf("%d\n",p.len);
                    break;
                }
                for(int i = 0;i < 3;i++){
                    for(int j = 0;j < 3;j++){
                        if(i==j) continue;
                        else{
                            node p1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
