#include <bits/stdc++.h>
using namespace std;
char a[105];
int b[105][105];
char az[3];
char aa[3];
/* char za[3] = {'Z','A'}; */
int main(){
    int n,mx = 0,ans = 0;
    
    scanf("%d%s",&n,a);
    for(int j = 0;j < n-1;j++){
        ans = 0;
        az[0] = a[j],az[1] = a[j+1];
        for(int i = 0;i < n-1;i++)
        {
            if(az[0]==a[i]&&az[1]==a[i+1]){
                ans++;
            }
        }
        if(mx < ans){
            mx = ans;
            aa[0] = az[0];
            aa[1] = az[1];
        }
    }
    printf("%s\n",aa);
    return 0;
}
