#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int ans[1000010];
map<int,int>mp;
int main(){
    scanf("%s",s);
    int len = strlen(s);

    
    if(s[0]=='G') ans[0]=1;
    else          ans[0]=-1;
    
    for(int i = 1;i < len;i++){
        if(s[i]=='G')
            ans[i]=ans[i-1]+1;
        else ans[i]=ans[i-1]-1;
    }

    int ans1 = 0;
    for(int i = 0;i < len;i++){
        if(ans[i]==0)
            ans1 = max(ans1,i+1);
        else{
            if(!mp.count(ans[i])){
                mp[ans[i]] = i;
            }
            else{
                ans1 = max(ans1,i-mp[ans[i]]);
            }
        }
    }

    printf("%d\n",ans1);

    return 0;
}
