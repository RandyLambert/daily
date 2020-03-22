#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int cmp(int x,int y){
    return x > y;
}
int aa[12346] = {0};
int main(){
    int t,xi,n,mx = 0,ci = 0,xx = 0;
    scanf("%d",&t);
    while(getchar()!='\n');
    while(t--){
        scanf("%d",&n);
        getchar();
        for(int i = 0;i < n;i++){
            scanf("%d",&xi);
            aa[xi] = aa[xi] + 1;
            mx = max(mx,xi);
        }
            while(getchar()!='\n');

        for(int i = 0;i <= mx;i++ ){
            if(aa[i]!=0){
                ci++;
            }
        }
        sort(aa,aa+mx+1,cmp);
        for(int i = 0;i <= ci;i++){
            if(aa[0] == aa[i]){
                xx++;
            }
        }
        printf("%d\n",ci-xx);
        ci = 0;
        mx = 0;
        xx = 0;
        memset(aa,0,mx+1);
    }
    return 0;
}
