#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
bool mp[N];
vector<int> perm;
int main()
{
    int t;
    for(int i = 2;i < N;i++){
        int x = (int)sqrt(i);
        bool is = true;
        for(int j = 1; j <= x;j++){
            if(j == 1)
                continue;
            if(i%j == 0){
                is = false;
                break;
            }
        }
        mp[i] = is;
        if(is == true)
            perm.push_back(i);
    }
    scanf("%d",&t);
    int n;
    for(int i = 0;i < t;i++){
        scanf("%d",&n);
        for(const auto x : perm){
            if(mp[n-x] == true){
                printf("%d %d\n",x,n-x);
                break;
            }
        }
    }
    
    return 0;
}
