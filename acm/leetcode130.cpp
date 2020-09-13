#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    queue<pair<int,int>> que;
    int nx[4] = {0,1,-1,0};
    int ny[4] = {1,0,0,-1};

    bool check(int x,int y,vector<vector<char>>& board){
        if(x >= 0 && y >= 0 && x < board.size()&& y < board[0].size() && board[x][y] == 'O'){
            return true;
        }
        else{
            return false;
        }
    }

    void bfs(pair<int,int> pos,vector<vector<char>>& board,bool flag){
        while(!que.empty())
            que.pop();

        que.push(pos);
        while(!que.empty()){
            auto top = que.front();
            que.pop();
            for(int i = 0;i < 4;i++){
                int x = top.first  + nx[i];
                int y = top.second + ny[i];
                if(check(x,y,board)){
                    que.push({x,y});
                    if(flag == false)
                        board[x][y] = 'Z';
                    else if(flag == true)
                        board[x][y] = 'X';
                }
            }    
        }
    }

    void solve(vector<vector<char>>& board) {
        //cout<<board.size()<<endl;
        //cout<<board[0].size()<<endl;
    
        if(board.size() == 0){
            return;
        }

        for(int i = 0;i < board.size();i++){

            if(board[i][0] == 'O'){
                board[i][0] = 'Z';
                bfs({i,0},board,false);    
            }

            if(board[i][board[0].size()-1] == 'O'){
                board[i][board[0].size()-1] = 'Z';
                bfs({i,board[0].size()-1},board,false);    
            }
        }

        for(int i = 0;i < board[0].size();i++){
            if(board[0][i] == 'O'){
                board[0][i] = 'Z';
                bfs({0,i},board,false);    
            }

            if(board[board.size()-1][i] == 'O'){
                board[board.size()-1][i] = 'Z';
                bfs({board.size()-1,i},board,false);    
            }
        }

        for(int i = 1;i < board.size()-1;i++){
            for(int j = 1 ;j < board[i].size()-1;j++){
       // cout<<"dasdsa"<<endl;
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                    bfs({i,j},board,true);
                }
            }
        }

        for(int i = 0;i < board.size();i++){
            for(int j = 0 ;j < board[i].size();j++){
                if(board[i][j] == 'Z'){
                    board[i][j] = 'O';
                } 
            }
        }
    }
};

int main()
{
    Solution a;
    vector<vector<char>> aa{{'X','X','X','X','X'},{'X','O','O','X','X'},{'X','X','O','X','X'},{'X','O','X','X','X'}};
    a.solve(aa);
    return 0;
}
