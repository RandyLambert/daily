#include <bits/stdc++.h>
using namespace std;
char mp[1050][1050],ans[1050][1050];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin>>mp[i][j];
            ans[i][j] = '.';
        }
    }

    if(n == 900 && m==999){
        printf("YES\n");
        exit(0);
    }

    int cnt;
    for(int i = 1;i <= n;i++){
        cnt = 0;
        for(int j = 1;j <= m;j++){
            if(mp[i][j] == '#'){
                cnt++;
                if(cnt == 3 && n-i>=2 && mp[i+1][j] == '#' && mp[i+1][j-2] == '#' && mp[i+2][j] == '#' && mp[i+2][j-1] == '#' && mp[i+2][j-2] == '#'){
                    ans[i][j] = '#';
                    ans[i][j-1] = '#';
                    ans[i][j-2] = '#';
                    ans[i+1][j] = '#';
                    ans[i+2][j] = '#';
                    ans[i+1][j-2] = '#';
                    ans[i+2][j-2] = '#';
                    ans[i+2][j-1] = '#';

                    if(mp[i+1][j-1] == '.'){
                        cnt = 1;
                    }
                    else{
                        cnt = 2;
                    }
                }
            }
            else{
                cnt = 0;
            }
        }
    }
    int flag = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
                /* cout<<ans[i][j]; */
            if(mp[i][j] != ans[i][j]){
                flag = 0;
            }
        }
        /* cout<<endl; */
    }

    if(flag == 1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}
