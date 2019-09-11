#include<bits/stdc++.h>

using namespace std;

int aa[102],bb[102],mi1 = 0,mx1 = 0;
int cmp(int x,int y){
    return x>y;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n ;i++){
        cin>>aa[i];
        bb[i] = aa[i];
    }
    if(n>1){
        int xx = n;

        for(int i = 0;i < n;i++){
            sort(aa,aa+xx,cmp);
            aa[xx-2] = aa[xx-1] + aa[xx-2];
            mi1 = mi1 + aa[xx-2];
            xx--;
            /* printf("%d\n",aa[xx-2]); */
        }

        xx = n;
        for(int i = 0;i < n-1;i++){
            sort(bb,bb+xx);
            bb[xx-2] = bb[xx-1] + bb[xx-2];
            mx1 = mx1 + bb[xx-2];
            xx--;
        }
        printf("%d\n%d",mi1,mx1);
    }
    else{
        printf("%d\n%d",aa[0],aa[0]);
    }
    
    return 0;
}
