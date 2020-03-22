#include <bits/stdc++.h>
using namespace std;

int vis[101],print[101];
int main(){
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++){
        scanf("%d%d",&a,&b);
        for(int i = a;i <= b;i++){
            vis[i] = 1;
        }
    }
    int k = 0,tex = 0;
    for(int i = 1;i <= m;i++ ){
        if(vis[i]==0){
            print[k] = i;
            tex++;
            k++;
        }
    }
    if(tex==0){
        printf("0\n");
    }
    else{
        printf("%d\n",tex);
        for(int i = 0;i < k;i++)
            printf("%d ",print[i]);
        putchar('\n');
    }
    return 0;
}
