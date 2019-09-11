#include <bits/stdc++.h>
using namespace std;
int n,m,ans = 0;
int book[35];
typedef struct node{
    int ci;
    int num;
}node;
queue <node> q;
int main(){
    scanf("%d%d",&n,&m);
    node start;
    start.ci = 0;
    start.num = 1;
    q.push(start);
    while(!q.empty()){
        node temp = q.front();
        q.pop();
        if(temp.ci == m && temp.num == 1){
            ans++;
        }
        else if(temp.ci < m){
            int ci = temp.ci + 1;
            if(temp.num == 1){
                if(temp.ci == 0){
                     node nw;
                     nw.ci = ci;
                     nw.num = 2;
                     q.push(nw);
                     
                     nw.ci = ci;
                     nw.num = n;
                     q.push(nw);
                }
            }
            if(temp.num == n){
                if(temp.ci != m-1){
                    node nw;
                    nw.ci = ci;
                    nw.num = 1;
                    q.push(nw);

                    nw.ci = ci;
                    nw.num = n-1;
                    q.push(nw);
                }
                else{
                    node nw;
                    nw.ci = ci;
                    nw.num = 1;
                    q.push(nw);
                }
            }
            else{
                node nw;
                nw.ci = ci;
                nw.num = temp.num+1;
                q.push(nw);
                if(temp.num - 1!=1&&nw.ci!=m){
                    nw.num = temp.num-1;
                    q.push(nw);
                }
            }
        }
    }
    printf("%d\n",ans);

    return 0;
}

