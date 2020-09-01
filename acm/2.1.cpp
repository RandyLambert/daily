#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int n,a[1001],b[1001];
int main(){
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    int j = 0;
    for(int i = n - 1;i >= 0;i--){
        if(b[a[i]] == 0){
            b[a[i]] = 1;
            j++;
        }
        else if(b[a[i]] == 1){
            a[i] = 1000000;
        }
    }
    printf("%d\n",j);
    for(int i = 0;i < n;i++){
        if(a[i] != 1000000)
            printf("%d ",a[i]);
    }
    return 0;
}
