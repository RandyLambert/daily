#include <iostream>
#include <algorithm>
using namespace std;
int ans[4];
int main()
{
    int x = 0;
    int cnt = 0;
    int z = 0;
    cin>>z;
    while(1){
        if(cnt == 0 || cnt == 1 || cnt == 2){
            cnt++;
            ans[x] = 1;
            x++;
        }
        else{
            cnt++;
            ans[x] = 0;
            if(x-1 < 0){
                ans[x]=(ans[x]+ans[x+4-1])%10000;
            }
            else{
                ans[x]=(ans[x]+ans[x-1])%10000;
            }

            if(x-2 < 0){
                ans[x]=(ans[x]+ans[x+4-2])%10000;
            }

            else{
                ans[x]=(ans[x]+ans[x-2])%10000;
            }

            if(x-3 < 0){
                ans[x]=(ans[x]+ans[x+4-3])%10000;
            }
            else{
                ans[x]=(ans[x]+ans[x-3])%10000;
            }

            if(cnt == z){
                cout<<ans[x]<<endl;
                return 0;
            }
            x = (x+1)%4;
        }
    }
    return 0;
}
