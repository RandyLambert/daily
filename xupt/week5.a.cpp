#include <stdio.h>
#include <string.h>
int mp[105][105];
int zong[105];
int max(int a,int b){
    if(a>b)return a;
    else return b;
}
int main(){
    int ci;
    scanf("%d",&ci);
    while(ci--){
        memset(mp,0,sizeof(mp));
        memset(zong,0,sizeof(zong));
        int n;
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            for(int j = 0;j <= i;j++){
                scanf("%d",&mp[i][j]);
            }
        }

        /* for(int i = 0;i < n;i++){ */
        /*     for(int j = 0;j < n;j++){ */
        /*         printf("%d ",mp[i][j]); */
        /*     } */
        /*     putchar('\n'); */
        /* } */
        for(int i = 0;i < n;i++){
            zong[i] = mp[n-1][i];
        }

        for(int i = n-1;i >0;i--){
            for(int j = 0;j < i;j++){
                zong[j] = max(zong[j] + mp[i-1][j],zong[j+1] + mp[i-1][j]);
            }

            /* for(int i = 0;i < n;i++){ */
            /*     printf("%d ",zong[i]); */
            /* } */
            /* putchar('\n'); */

        }
        printf("%d",zong[0]);
    }

    return 0;
}
