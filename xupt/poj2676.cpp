#include <bits/stdc++.h>
using namespace std;
char mp[9][9];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i = 0;i < 9;i++){
            scanf("%s",mp[i]);
        }

        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                printf("%c ",mp[i][j]);
            }
            putchar('\n');
        }
    }

    return 0;
}

