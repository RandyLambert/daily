#include<stdio.h>
#include <queue>
#include <vector>
using namespace std;
vector<int>a[500005];
int book[5005],vis[5005],f[5005];
queue<int>q;
int main(){
    int n,m,temp1,temp2,sum = 0;

    scanf("%d%d",&n,&m);
    for(int i = 0;i < m;i++){
        scanf("%d%d",&temp1,&temp2);
        a[temp1].push_back(temp2);
        vis[temp1]++;
        book[temp2]++;
    }

    for(int i = 1;i <= n;i++){
        if(book[i]==0){
            q.push(i);
            f[i] = 1;
        } 
    }
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i = 0;i < a[temp].size();i++){
            f[a[temp][i]]+=f[temp];
            f[a[temp][i]]%=80112002;
            book[a[temp][i]]--;
            if(book[a[temp][i]] == 0){
                if(vis[a[temp][i]] == 0){
                    sum+=f[a[temp][i]];
                    sum%=80112002;
                }
                q.push(a[temp][i]);
            }
        }
    }
    printf("%d\n",sum);
    return 0;
}
