#include <bits/stdc++.h>
using namespace std;
char a[110];
int mp1[128];
int mp2[128];
int ans[110];
int main(){
    scanf("%s",a);
    int len = strlen(a);
    int cnt = 0;
    mp1[a[0]] = 1;
    mp2[a[0]] = 0;
    ans[0] = 1;

    for(int i = 1;i < len;i++){
        if(mp1[a[i]] == 0){
            ans[i] = ans[i-1]+1;
            mp1[a[i]] = 1;
            mp2[a[i]] = i;
        }
        else{
            ans[i] = i - mp2[a[i]];
            mp2[a[i]] = i;
        }
        cnt = max(ans[i],cnt);
    }

    printf("%d\n",cnt);
    return 0;
}
