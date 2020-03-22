#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int a[4][4] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},n;
inline int findf(int i,int j){
    return ((n/4)*(i/4))+j/4;
} 
int main(){

    cin>>n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cout<<findf(i,j)*16+a[i%4][j%4]<<" ";
        }
        cout<<"\n";
    }


    return 0;
}

