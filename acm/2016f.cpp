#include <algorithm>
#include <iostream>
using namespace std;
int mp[4][5];
bool used[10];
bool judge(int x,int y){
    if(x-1)
}
void dfs(int x,int y){
    
    for(int i = 0;i < 10;i++){
        if(used[i] == false){
            if(judge(x,y)){
                used[i] = true;
                if(x+1!=4)
                    dfs(x+1,y);
                if(y+1!
                used[i] = false;
            }
        } 
    }
}

int main()
{

    dfs();

    return 0;
}
