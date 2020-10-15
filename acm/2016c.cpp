#include <algorithm>
#include <iostream>
using namespace std;
bool used[10] = {false};
double a[10];
int cnt = 0;
void dfs(int x){
    if(x == 10){
        /*for(auto x : a){
            cout<<x;
        }
        cout<<endl;*/

        if(a[1] + a[2]/a[3] + (a[4]*100+a[5]*10+a[6])/(a[7]*100+a[8]*10+a[9]) == 10){
            cnt++;
        }
        return ;
    }

    for(int i = 1;i < 10;i++){
        if(used[i] == false){
            a[x] = i;
            used[i] = true;
            dfs(x+1);
            used[i] = false;
        }
    }
    return;
}
int main()
{
    dfs(1);
    cout<<cnt<<endl;
    return 0;
}
