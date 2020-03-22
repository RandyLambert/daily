#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fib[70];
int ansl[300],ansr[300];

int main(){

    fib[1] = 1,fib[2] = 2;
    for(int i = 3;i < 70;i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    int n;

    while(cin >> n){
        memset(ansl,0,sizeof(ansl));
        memset(ansr,0,sizeof(ansr));

        if(n == 0){
            printf("2\n1 1\n2 1\n");
            continue;
        }
        else{

            int ans = 1;
            int x= 50;
            int y = 0;
            while(n){
                while(fib[x] > n){
                    x--; 
                }
                n = n - fib[x];
                ansr[y] = 200 - x;
                ansl[y++] = ans;
                ans+=2;
            }
            ansr[y] = --ans;
            ansl[y++] = ans;

            printf("%d\n",y);
            for(int i = 0;i < y;i++){
                printf("%d %d\n",ansl[i],ansr[i]);
            }
        }
    }
    return 0;
}

