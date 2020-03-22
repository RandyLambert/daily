#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int c[2108];
int main(){
    int n,b,a;

    scanf("%d%d%d",&n,&a,&b);
    for(int i = 1;i <= n;i++){
        scanf("%d",&c[i]);
    }
    int x = 1;
    int a1 = a;
    int b1 = b;
    while(!(b1==0&&a1==0)){
        printf("%d%d\n",a1,b1);
        if(c[x] == 1){
            if(a1>=0){
                if(a1<a){
                    a1++;
                }
                if(a1 >= 1)
                a1--;
            }
            else if(b1 >= 1){
                b1--;
            }
            else break;
        }
        else if(c[x] == 0){
            if(a1>=1)
                a1--;
            else if(b1 >= 1)
                b1--;
            else break;
        }
        x++;
    }
    printf("%d",x - 1);

    return 0;
}
