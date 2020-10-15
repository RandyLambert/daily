#include <algorithm>
#include <iostream>
using namespace std;
int a[100];
int main()
{

    a[1] = 1;
    int cnt = 236;
    for(int i = 2;i < 100;i++){
        a[i] = i+a[i-1];
    }

    for(int i = 2;i < 100;i++){
        for(int j = i+1;j < 100;j++){
            if(a[j] - a[i] == 236){
                cout<<i+1<<endl;
            }
        }
    }
    return 0;
}
