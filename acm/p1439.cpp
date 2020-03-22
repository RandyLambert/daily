#include <bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int c[100010][2];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i < n;i++){
        scanf("%d",&b[i]);
    }
    for(int i = 0;i < n+1;i++){
        for(int j = 0;j < n+1;j++){
            c[i][0] = c[i][1] = 0;
        }
    }

    for(int i = 0;i < n+1;i++){
        for(int j = 0;j < n+1;j++){
            if(a[i-1]==b[j-1]){
                c[j][0] = c[j-1][1]+1;
            }
            else{
                c[j][0] = max(c[j-1][0],c[j-1][1]);
            }
        }
    }
    printf("%d\n",c[n][0]);
    return 0;
}
