#include <bits/stdc++.h>
using namespace std;
int a[1005];
bool a1[2005];
int b[2005];
int gcd(int x,int y){
    if(x!=0){
        gcd(x%y,x);
    }
    else{
        return y;
    }
}
int main(){
    memset(a1,1,sizeof(a1));
    a1[0] = a1[1] = 0;
    int ci = 0;
    for(int i = 2;i < 2005;i++){
        if(a1[i]) b[++ci] = i;
        for(int j = 1;j<i&&b[j]*i<2005;j++){
            a1[b[j]*i] = 0;
            if(i%b[j]==0) break;
        }
    }

    int n,flag = 0;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
        /* if(a1[i] == 1){ */
        /*     flag = 1; */
        /* } */
    }
    if(flag == 0){
        
        printf("-1\n");
    }
    else{
        printf("%d\n",n);
    }

    return 0;
}

