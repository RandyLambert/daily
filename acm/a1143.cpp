#include <iostream>
#include <cstring>
using namespace std;
int ansMap[4][4];
bool isUsing[11] = {false,false,false,false,false,false,false,false,false,false,false};
int ans = 0;
bool check(){
    int x1[4],x2[4];
    memset(x1,0,sizeof(x1));
    memset(x2,0,sizeof(x2));
    for(int i = 1; i <= 3;i++){ 
        for(int j = 1; j <= 3;j++){
            x1[j] += ansMap[i][j];
            x2[i] += ansMap[i][j];
        }
    }

    if((x1[1] == x1[2] == x1[3]) && (x2[1] == x2[2] == x2[3]))
        return true;
    else
    {
        return false;
    }
        
}
void dfs(int x,int y){
    if(x == 3 && y == 3 && check()){
        ans++;
        return ;
    }

    for(int k = 1; k <= 9;k++){
        if(!isUsing[k])
        {
            isUsing[k] = true;
            ansMap[x][y] = k;
            if(x + 1 <= 3)
                dfs(x+1,y);
            if(y + 1 <= 3)
                dfs(x,y+1);
            ansMap[x][y] = 0;
            isUsing[k] = false;
        }
        
    }

}
int main()
{
    dfs(1,1);
    cout << ans <<endl;
    return 0;
}