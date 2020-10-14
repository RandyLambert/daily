#include <algorithm>
#include <map>
#include <queue>
#include <iostream>
#include <string>
using namespace std;
class node{
public:
    int first;
    int second;
    string lu;
    node(){}
    node(int first_,int second_,string lu_):first(first_),second(second_),lu(lu_){}
};

int nx[4] = {0,-1,1,0};
int ny[4] = {-1,0,0,1};

map<int,char> mp{{0,'L'},{1,'U'},{2,'D'},{3,'R'}};
bool vis[55][55];
char tu[55][55];

int maxx;
int maxy;

bool check(int x,int y){
    if(vis[x][y] == true || tu[x][y] == '1' || x < 0 || y < 0 || x >= maxx || y >= maxy){
        return false;
    }
    else{
        return true;
    }
}
int main()
{

    cin>>maxx>>maxy;
    queue<node> que;
    
    for(int i = 0; i < maxx;i++){
        cin>>tu[i];
    }

/*    cout<< maxx<<maxy;
    for(int i = 0;i < maxx;i++){
        for(int j = 0;j < maxy;j++){
            cout<<tu[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    que.push(node(0,0,""));
    
    while(!que.empty()){
        node temp = que.front();
        que.pop();
        
        int x = temp.first;
        int y = temp.second;
        string path = temp.lu;

        if(temp.first == maxx-1 && temp.second == maxy-1){
        
            cout<<temp.lu<<endl;
            break;
        }

        for(int i = 0;i < 4;i++){
            int xx = x  + nx[i];
            int yy = y + ny[i];
            
            if(check(xx,yy)){
                vis[xx][yy] = true;
                que.push(node(xx,yy,temp.lu+mp[i]));                           
            }
        }
        
    }


    return 0;
}
