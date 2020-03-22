#include<stdio.h>
int nn[10001],mm[10001],zz[10001];
int main(){
    int n,m,y,x;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&nn[i]);
        zz[i] = zz[i-1]+nn[i];
    }
    for(int i = 1;i <= m;i++){
        scanf("%d",&mm[i]);
        y = zz[n];
        x = 0;
        while(x<=y){
            int mid = (x+y)/2;
            if(mid < mm[i]){
                x = mid+1;
            }
            else if(mid > mm[i]){
                y = mid-1;
            }
            else{
                x = mid;
                break;
            }
        }
        for(int i = 1;i <= n;i++){
            if(mm[i] > x){
                
            }
        }
        printf("%d \n",x);
    }

    /* for(int i = 1;i <= m;i++){ */

    /* } */

    return 0;
}
