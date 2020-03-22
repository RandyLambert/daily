#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
int a[100000+10];
int a1[100000+10];
int b1[100000+10];

int main(){

    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        int cnt1 = 0,cnt2 = 0;

        memset(a,0,sizeof(a));
        memset(a1,0,sizeof(a1));
        memset(b1,0,sizeof(b1));

        scanf("%d",&n);
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&a[i]);
        }

        a1[0] = a[0];
        b1[0] = a[0];

        for(int i = 1;i < n;i++)
        {
            if(a1[cnt1]<=a[i]){

                a1[++cnt1] = a[i];
            }
            else{
                int y = upper_bound(a1,a1+cnt1,a[i]) - a1;
                a1[y] = a[i];
            }

            if(b1[cnt2]>=a[i]){
                b1[++cnt2] = a[i];
            }
            else{
                int y = upper_bound(b1,b1+cnt2,a[i],greater<int>()) - b1;
                b1[y] = a[i];
            }

        }
        if(cnt1+1 >= n-1 || cnt2+1 >= n-1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
