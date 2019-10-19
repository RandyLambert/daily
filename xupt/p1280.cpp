#include <bits/stdc++.h>
using namespace std;
int dp[10010],sum[10010];
pair<int,int> ren[10010];
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second == b.second){
        return a.first > b.first;
    }
    else{
        return a.first > b.first;
    }
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);

    for(int i = 1;i <= k;i++){
        int x1,x2;
        scanf("%d%d",&x1,&x2);
        ren[i].first = x1,ren[i].second = x2;
        sum[ren[i].first]++;
    }

    sort(ren+1,ren+k+1,cmp);

    int flag = 1;

    for(int i = n;i >= 1;i--){
        if(sum[i] == 0)
            dp[i] = dp[i+1]+1;//起点的标记
        else
            for(int j = 1;j <= sum[i];j++){
                dp[i]=max(dp[i+ren[flag].second],dp[i]);
                //判断在所有起点相同的情况下，哪一个可以使他的空闲时间最大
                flag++; //判断这几个点走过了
            }

    }
    printf("%d\n",dp[1]);
    return 0;
}
