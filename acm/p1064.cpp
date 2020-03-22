#include<bits/stdc++.h>

using namespace std;
int a[30005];
int main(){
    int w,n,xx = 0;
    scanf("%d%d",&w,&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }

    sort(a,a+n);
    int x = 0;
    int y = n-1;
    while(x<=y){
        if(a[x]+a[y]<=w){
            xx++;
            x++;
            y--;
        }
        else{
            xx++;
            y--;
        }
    }
    printf("%d",xx);
    
    return 0;
}
