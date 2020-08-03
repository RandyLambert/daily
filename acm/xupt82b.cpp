#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long buf[200000+1000];
int main()
{
    long long k,m,n,p;

    while(scanf("%lld %lld %lld %lld",&k,&m,&n,&p)!=EOF){
        memset(buf,0,sizeof(buf));
        for(long long i = 0;i < k;i++){
            scanf("%lld",&buf[i]);
        }
        sort(buf,buf+k);
        long long bei = 1,flag = 0,ans = 0,bei2 = 1;

        for(long long i = 1;i < m;i++){
            bei = bei*n;
            bei2 += bei;
            for(long long j = flag;j < bei+flag;j++){
                ans = (ans + (((long long)(pow(n,m-i-1)))*buf[j]));

                /* ans += (m-i)*buf[j]; */
                cout <<((bei2-flag)*buf[j]) <<" "<< j <<endl;
                /* cout <<(bei2-flag) <<" "<< j <<endl; */
            }
            flag = bei+flag;
        }
        printf("%lld\n",ans);
    }

    return 0;
}

