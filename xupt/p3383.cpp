#include <bits/stdc++.h>
using namespace std;  
int sushu[1001];
bool su[1001];
int main(){
    int n,m,num = 1;
    scanf("%d%d",&n,&m);
    memset(su,1,sizeof(su));
    for(int i = 2;i <= n;i++ ){
        if(su[i]) sushu[num++] = i;
        for(int j = 1;j < num;j++){
            if(sushu[j]*i > n) break;
            su[sushu[j]*i] = 0;
            if(i%su[j] == 0) break;
        }
    }
    for(int i = 0; i < 100;i++){
        printf("%d ",su[i]);
    }
    int xx;
    for(int i = 0;i < m;i++){
        scanf("%d",&xx);
        if(su[xx]==1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
