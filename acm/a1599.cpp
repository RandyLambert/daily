#include <bits/stdc++.h>
using namespace std;
int mp[12][12];
bool check(int x,int y,int value) {
    if( mp[x][y] != 0){
        return false;
    }
    for(int i = 1;i < 10;i++){
        if(mp[x][i] == value || mp[i][y] == value){
            return false;
        }
    }
    int nx = (x-1)/3*3+1;
    int ny = (y-1)/3*3+1;
    for(int i = nx;i < nx+3;i++){
        for(int j = nx;j < ny+3;j++){
            if(mp[i][j] == value){
                if(i == x && j == y)
                    continue;
                else
                    return false;
            }
        }
    }
    return true;
}
void dfs(int x,int y){
    if(x == 9 && y == 9){

        for(int i = 1; i < 10;i++){
            for(int j = 1; j < 10;j++){
                cout<<mp[i][j]<<" ";
                // cout<<mp2[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        // getchar();
        // getchar();
        // getchar();
        return ;
    }
    for(int i = 1;i < 10;i++){
        if(check(x,y,i)){

            mp[x][y] == i;
                dfs(x+(y+1)/10,(y+1)%10);
            mp[x][y] == 0;
         }
    }

}


int main(){
    for(int i = 1; i < 10;i++){
        for(int j = 1; j < 10;j++){
            cin >> mp[i][j];
        }
    }

    dfs(1,1);
    for(int i = 1; i < 10;i++){
        for(int j = 1; j < 10;j++){
            cout<<mp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}