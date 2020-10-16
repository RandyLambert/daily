#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char mp[1010][1010];
bool used[1010][1010];
int nx[4] = {1,-1,0,0};
int ny[4] = {0,0,-1,1};
int n;

bool judge(int xx,int yy){
    if(xx < 0 || xx >= n || yy < 0 || yy > n || used[xx][yy] == true || mp[xx][yy] == '.' || mp[xx][yy] == '@'){
        return false;
    }
    return true;
}

bool judge2(int i,int j){
    bool flag = false;
    if( i-1 >= 0){
        if(mp[i-1][j] == '.'){
            flag = true;
        }
    }
    if(j-1 >= 0){
        if(mp[i][j-1] == '.'){
            flag = true;
        }
    }
    if( i+1 < n){
        if(mp[i+1][j] == '.'){
            flag = true;
        }
    }
    if(j+1 < n){
        if(mp[i][j+1] == '.'){
            flag = true;
        }
    }
    return flag;
}

void bfs(int i,int j){
    
    queue<pair<int,int>> que;
    pair<int,int> a(i,j);
    que.push(a);
    used[i][j] = true;
    while(!que.empty()){
        pair<int,int> temp = que.front();
        que.pop();
        
        for(int i = 0;i < 4;i++){
            int xx = nx[i] + temp.first;
            int yy = ny[i] + temp.second;
            if(judge(xx,yy)){
                pair<int,int> par(xx,yy);
                used[xx][yy] = true;
                que.push(par);
                
            }
        }
    }

}
int main()
{
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>mp[i];
    }

    int cnt = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(used[i][j] == false && mp[i][j] == '#'){
                cnt++;
                bfs(i,j);
            }
        }
    }

    //cout<<cnt<<endl;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(judge2(i,j) && mp[i][j]=='#'){
                mp[i][j] = '@';
            }
            //cout<<mp[i][j];
        }
        //cout<<endl;
    }

    memset(used,0,sizeof used);
    int ans = 0;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(used[i][j] == false && mp[i][j] == '#'){
                ans++;
                bfs(i,j);
            }
        }
    }

    cout<<cnt-ans<<endl;

    return 0;
}
