#include<bits/stdc++.h>
using namespace std;
int mp[25] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930,4060, 4970, 5030, 5990, 6010, 7000};
int main(){
    int a,b,n,mv[25] = {0};
    scanf("%d%d%d",&a,&b,&n);
    for(int i = 14;i < 14 + n;i++){
        scanf("%d",&mp[i]);
    }
    sort(mp,mp+14+n);
    mv[0] = 1;

    for(int i = 0;i < 14+n;i++){
        for(int j = 0;j < i;j++){

            if(mp[i]-mp[j]<=b&&mp[i]-mp[j]>=a){
                mv[i] = mv[i] + mv[j];
            }
        }
    }

    printf("%d",mv[13+n]);
    return 0;
}
