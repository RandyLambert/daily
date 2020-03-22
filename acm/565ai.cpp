#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n,x;
    scanf("%lld",&n);
    while(n--){
        long long int tt = 0,flag = 0;
        scanf("%lld",&x);
        while(1){
            if(x%2==0){
                x=x/2;
                tt++;
                if(x==1){
                    flag = 1;
                    break;
                }
                /* printf("%lld\n",x); */
            }
            else if(x%3==0){
                x=x/3*2;
                tt++;
                if(x==1){
                    flag = 1;
                    break;
                }
            }
            else if(x%5==0){
                x=x/5*4;
                tt++;
                if(x==1){
                    flag = 1;
                    break;
                }
            }
            else if(x==1){
                flag = 1;
                break;
            }
            else{
                break;
            }
        }
        if(flag == 0)
            printf("-1\n");
        else
            printf("%lld\n",tt);
    }

    return 0;
}

