#include <bits/stdc++.h>
using namespace std;
char a[200100];
int main(){
    int n,ans = 0,temp = 0;
    scanf("%d",&n);
    scanf("%s",a);
    while(temp < n){
        if(a[temp] == a[temp+1]){
            a[temp]=0;
            ans++;
            temp++;
        }
        else{
            temp+=2;
        }
    }
    if((n-ans)%2==1){
        a[n-1]=0;
        ans++;
    }
    printf("%d\n",ans);
    for(int i = 0;i < n;i++){
        if(a[i]!=0)
            printf("%c",a[i]);
    }

    return 0;
}
