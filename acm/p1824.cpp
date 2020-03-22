#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int n,c;
int panduan(int x){
    int cc = 1;
    int last = a[0];
    for(int i = 1;i < n;i++){
        if(a[i]-last >= x){
            cc++;
            last = a[i];
        }
    }
    /* printf("%d  ",cc); */
    if(cc >= c) return 1;
    else return 0;
}
int main(){
    scanf("%d%d",&n,&c);
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int l = 1;
    int r = a[n-1];
    while(l<=r){
        int mid = (l + r)/2;
        /* printf("mid = %d\n",mid); */
        if(panduan(mid)){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }

    printf("%d",l-1);
    return 0;
}
