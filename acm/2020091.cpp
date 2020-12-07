#include <iostream>
#include <algorithm>
using namespace std;
struct ce{
    int X;
    int Y;
    int ans;
    int i;
    bool operator <(const ce& d){
        if(ans < d.ans){
            return true;
        }
        else if(ans == d.ans){
            return i < d.i;
        }
        return false;
    }
} jian[1000];
int main()
{
    int n,X,Y;
    cin>>n>>X>>Y;
    for(int i = 0;i < n;i++){
        cin >> jian[i].X >> jian[i].Y;
        jian[i].i = i+1;
        jian[i].ans = (jian[i].X - X)*(jian[i].X - X) + (jian[i].Y - Y)*(jian[i].Y - Y);
    }

    sort(jian,jian+n);
    for(int i = 0;i < 3;i++){
        cout<<jian[i].i<<endl;
    }
    return 0;
}
