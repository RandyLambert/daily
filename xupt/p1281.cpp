#include <bits/stdc++.h>
using namespace std;
int a[550],m,k,ans=1;
int mp[2][550];
int judge(int mid){
    int cnt=m,i=m,j=m,sum=0;
    ans=1;
    memset(mp,0,sizeof(mp));
    while(cnt >= 1){
        if(sum + a[cnt] <= mid){
            sum = sum + a[cnt];
            cnt--;
            j--;
            if(cnt == 0){
                mp[0][ans] = i;
                mp[1][ans] = j+1;
            }
        }
        else{
            if(cnt!=1){
                mp[0][ans] = i;
                mp[1][ans] = j+1;
            }
            else{
                if(k!=4)
                {
                    mp[0][ans] = i;
                    mp[1][ans] = j;
                }
                else{
                    mp[0][ans] = i;
                    mp[1][ans] = j+1;

                }
            }
            i = j;
            sum = 0;
            ans++;
            if(ans > k){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    int ans;
    int sum = 0,ll = 312312321;  
    scanf("%d%d",&m,&k);
    for(int i = 1;i <= m;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        ll = min(ll,a[i]);
    }
    int mid;
    int rr = sum;
    while(ll <= rr)
    {
        mid = (ll+rr)/2;
        if(judge(mid)){
            ans = mid;
            rr = mid-1;
        }
        else{
            ll = mid+1;
        }
    }
    printf("%d\n",ans);
    for(int i = k;i >= 1;i--){
        printf("%d %d\n",mp[1][i],mp[0][i]);
    }
    return 0;
}
