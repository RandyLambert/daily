#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    long long int ci;
    long long int num;
}node;

queue<node>q;

int main(){
    int t,da;
    scanf("%d",&t);
    while(t--){
        while(!q.empty()) q.pop();
        int flag = 0;
        scanf("%d",&da);
        node start;
        start.ci = 0;
        start.num = da;
        q.push(start);
        while(!q.empty()){
            node temp;
            temp = q.front();
            q.pop();
            if(temp.num == 1){
                flag=1;
                printf("%lld\n",temp.ci);
                break;
            }
            else{
                if(temp.num%2==0){
                    node nw;
                    nw.ci = temp.ci+1;
                    nw.num = temp.num/2;
                    q.push(nw);
                }
                if(temp.num%3==0){
                    node nw;
                    nw.ci = temp.ci+1;
                    nw.num = temp.num/3*2;
                    q.push(nw);
                }
                if(temp.num%5==0){
                    node nw;
                    nw.ci = temp.ci+1;
                    nw.num = temp.num/5*4;
                    q.push(nw);
                }
            }
        }
        if(flag==0)
            printf("-1\n");
    }

    return 0;
}

