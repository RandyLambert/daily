#include <bits/stdc++.h>
using namespace std;
int mp[100005],a,b;
inline int judge(int mid){
    int temp = mp[0];
    int ans = 1;
    int cnt = 1;
    while(cnt <= a-1)
    {
        if(mp[cnt]-temp < mid){
           cnt++;
        }
        else
        {
            temp = mp[cnt];
            ans++;
            if(ans>=b)
                return 1;
        }

    }
    /* printf("%d %d",mid,ans); */
    return 0;
}
int main(){
    int mid,ans = 0,l=1,r,ll=0,xx;
    scanf("%d%d",&a,&b);
    for(int i = 0;i < a;i++)
    {
        scanf("%d",&mp[i]);
        ll = min(ll,mp[i]);
        r = max(r,mp[i]);
    }
    sort(mp,mp+a);
    r = r - ll;
    while(l<=r)
    {
        mid = (l+r)>>1;
        if(judge(mid)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
