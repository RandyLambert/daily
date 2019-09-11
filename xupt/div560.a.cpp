#include <bits/stdc++.h>
using namespace std;
char a[200100];
int b[200100];
int main(){
    int n,x,y,ans = 0;
    scanf("%d%d%d",&n,&x,&y);
    scanf("%s",a);

    if(a[n-1-x]=='0'){
        ans++;
        a[n-1-x] = '1';
    }
    if(a[n-1-y]=='0'){
        ans++;
        a[n-1-y] = '1';
    }
    for(int i = n-1-x;i <= n;i++){
        if(i==n-1-y||i==n-1-x){
            continue;
        }
        else{
            if(a[i]=='1'){
                ans++;
                a[i]='0';
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
