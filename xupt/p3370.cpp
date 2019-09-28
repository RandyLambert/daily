#include <bits/stdc++.h>
using namespace std;
set<int> mp;
char a[10000+10];
typedef unsigned long long ull;
const int base = 131; 
int main(){
    int n;
    scanf("%d",&n);
    while(n--)
    {
        ull ans = 0;
        scanf("%s",a);
        int len = strlen(a);
        for(int i = 0;i < len;i++)
        {
            ans = ans*base + a[i];
        }

        mp.insert(ans);
    }

    printf("%ld\n",mp.size());
    return 0;
}

