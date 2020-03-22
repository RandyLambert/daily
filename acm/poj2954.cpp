#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int x1,y1,x2,y2,x3,y3;
    while(1){
        int ans = 0;
        int mian = 0;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        if(!(x1||y1||x2||y2||x3||y3)){
           break; 
        }
        
        mian = abs((x1-x2)*(y3-y2)-(x3-x2)*(y1-y2))+2;
        
        ans = ans + __gcd(abs(x1 - x2),abs(y1 - y2));
        ans = ans + __gcd(abs(x1 - x3),abs(y1 - y3));
        ans = ans + __gcd(abs(x2 - x3),abs(y2 - y3));

        cout<<(mian - ans)/2<<"\n";
    }

    return 0;
}

