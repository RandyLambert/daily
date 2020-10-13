#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a,b,n;
    cin>>a>>b>>n;
    int y = a%b;
    int z = 0;
    for(int i = 0;i < n-1;i++){
        y = y*10;
        z = y/b;
        if(z > 0){
            y = y - z*b;
        }
        //cout<<z<<endl;
    }

    for(int i = 0;i < 3;i++){
        y = y*10;
        z = y/b;
        if(z > 0){
            y = y - z*b;
        }
        cout<<z;
    }
    cout<<endl;
    return 0;
}
