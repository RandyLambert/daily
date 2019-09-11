#include <iostream>
#include <bits/stdc++.h>

int a[105];
int cc[105];
using namespace std;
int main(){
    int n,c1 = 0;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int x = 0;
    int xx = 0;
    for(int j = 0;j < n;j++ ){
        cc[a[j]]++;
    }
    
    for(int j = 0;j < 105;j++){
        if(cc[j] != 0){
            c1++;
            if(c1 == 2 ){
                xx = j;
            }
        }
    }
    if(c1 == 2){
        for(x = 1;x <= a[n-1];x++){
            if(a[0]+x == a[n-1]-x){
                break;
            }
        }
    }
    else if(c1 == 3){
        for(x = 1;x <= a[n-1];x++){
            if(a[0]+x == a[n-1]-x && a[0]+x == xx){
                break;
            }
        }
    }
    if(x == a[n-1]||c1>3)
        x = -1;
    printf("%d",x);
    return 0;
}
