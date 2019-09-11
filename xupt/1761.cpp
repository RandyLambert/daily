#include <iostream>
#include <stdio.h>
#include<algorithm>
using namespace std;
int t,n,mx,ny,flag,fl;
int main(){
    
    cin>>t;
    for(int i = 0;i < t;i++){
        cin>>n;
        mx = 0;
        for(int j = 0;j < n;j++){
            cin>>ny;
            if(ny == flag){
                if(fl < ny){
                fl = ny;
            }
                fl = fl + flag;
                mx = max(fl,mx);
            }
            else{
                fl = 0;
                mx = max(ny,mx);

            }
            flag = ny;
        }
        mx = max(mx,n);
        printf("%d\n",mx);
        flag = 0;
        mx = 0;
        fl = 0;
    }

    return 0;
}
