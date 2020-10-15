#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <queue>
#include <cstring>
using namespace std;
unordered_set<string> st;
int nx[4] = {1,0,-1,0};
int ny[4] = {0,-1,0,1};
int mp[4][5];
bool isused[4][5];
struct node{
    int x;
    int y;
    vector<int> path;
    node(){};
    node(int x_,int y_,vector<int> path_):x(x_),y(y_),path(path_){}
};

bool check(int x,int y,vector<int>& path){
    if(x<=0 || y<=0 || x>3 || y>4 || isused[x][y] == true || path.size()>5){
        return false;
    }else{
        return true;
    }
}
int main()
{
    int cnt = 1;
    for(int i = 1;i < 4;i++){
        for(int j = 1;j < 5;j++){
            mp[i][j] = cnt++;
        }
    }

    
    for(int i = 1;i < 4;i++){
        for(int j = 1;j < 5;j++){
            
            queue<node> q;
            memset(isused,0,sizeof(isused));

            vector<int> ins;
            ins.push_back(mp[i][j]);
            node first(i,j,ins);
            q.push(first);
            isused[i][j] = true;

            while(!q.empty()){
                node temp = q.front();
                q.pop();
                //for(auto x:temp.path){
                  //  cout<<x<<endl;
                //}

                if(temp.path.size() == 5){
                    sort(temp.path.begin(),temp.path.end());
                    string str;
                    for(int k = 0;k < temp.path.size();k++){
                        str += ('0' + temp.path[k]);
                    }
                    st.insert(str);
                }

                for(int k = 0;k < 4;k++){
                    int x = nx[k] + temp.x;
                    int y = ny[k] + temp.y;
                    if(check(x,y,temp.path)){
                        node tmp(x,y,temp.path);
                //for(auto x:tmp.path){
                  //  cout<<x<<endl;
                //}
                        tmp.path.push_back(mp[x][y]);
                        isused[x][y] = true;
                        q.push(tmp);
                    }
                }
            }
        }
    }
    cout<<st.size()<<endl;

    return 0;
}
