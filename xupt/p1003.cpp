#include <iostream>
#include <string.h>
int mp[5][10002];
int main(){
    int n,t3,t4,i,j=-1,x,y;
    scanf("%d",&n);
        for(i = 1;i <= n;i++){
            scanf("%d%d%d%d",&mp[1][i],&mp[2][i],&t3,&t4);
            mp[3][i] = t3+mp[1][i];
            mp[4][i] = t4+mp[2][i];
            mp[0][i] = i;
        }
    scanf("%d%d",&x,&y);
    for(int i = n;i >= 1;i-- ){
        if(mp[1][i]<=x&&mp[2][i]<=y&&mp[3][i]>=x&&mp[4][i]>=y){
            j = mp[0][i];
            break;
        }
    }
    printf("%d",j);
return 0;
}
