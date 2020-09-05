#include <iostream>
#include <queue>
using namespace std;
int nx[4] = {1,0,-1,0};
int ny[4] = {0,1,0,-1};
char mp[12][12] = { {0,0,0,0,0,0,0,0,0,0,0},
                    {0,1,1,1,1,1,1,1,2,1,1},
                    {0,1,1,1,-1,1,1,2,1,1,1},
                    {0,1,-1,1,1,2,1,1,-1,1,1},
                    {0,1,2,1,1,1,-1,1,1,2,1},
                    {0,1,-1,1,1,2,1,-1,1,1,1},
                    {0,1,1,-1,1,1,1,1,-1,1,1},
                    {0,1,1,1,1,1,-1,1,1,2,1},
                    {0,-1,1,-1,1,1,1,2,1,1,1},
                    {0,2,1,1,1,1,1,-1,-1,1,1},
                    {0,1,1,-1,1,1,-1,2,1,1,1}};
bool is[12][12];
bool check(int x,int y){
    if(x < 1 || y < 1 || x > 10 || y > 10 || mp[x][y] == -1 || mp[x][y] == 0 || is[x][y] == true)
        return false;
    else
        return true;
}
int main()
{
    queue<pair<int,int>> q;
    q.push({1,1});
    int cnt = 0;
    int max = 10;
    int ans = 0;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        ans ++;
        if(cnt == 10){
            break;
        }
        for(int i = 0;i < 4;i++){
            int xx = x.first + nx[i];
            int yy = x.second + ny[i];
            if(check(xx,yy)){
                if(mp[xx][yy] == 2){
                    cnt++;
                    if(cnt == max){
                        cout << xx << " "<< yy << " "<< ans <<endl;
                        break;
                    }
                }
                is[xx][yy] = true;
                q.push({xx,yy});
            }
        }
    }

    return 0;
}