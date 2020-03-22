#include<stdio.h>
#include<algorithm>
using namespace std; 
int a[1002],mx = -1,nub;
int cmp(int x,int y){
    return x>y;
}
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    
    if(m>=n){
        for(int i = 1;i <= n;i++){
            if(i*a[i]>mx){
                nub = a[i];
                mx = i*a[i];
            }
        }        
    }
    else{
        for(int i = 1;i <= m;i++){
            if(i*a[i]>mx){
                nub = a[i];
                mx = i*a[i];
            }
        }        
    }
    printf("%d %d",nub,mx);

    return 0;
}
