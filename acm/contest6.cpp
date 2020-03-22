#include <stdio.h>
#include <string.h>
char a[10000],b[10000],c[10000];
int min(int x,int y){
    if(x < y) return x;
    else return y;
}
int main(){
    int x;
    scanf("%d",&x);
    while(x--){
        int ans = 0;
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        memset(b,0,sizeof(b));
        scanf("%s%s",a,b);
        int la = strlen(a);
        int lb = strlen(b);
        int mi = min(la,lb);
        for(int i = 0;i < mi;i++){
            if(a[i] == b[i]){
                ans++;
                c[i] = a[i];
            }
            else{
                break; 
            }
        }
        if(ans == 0){
            printf("无公共前缀\n");
        }
        else{
            printf("%s\n",c);
        }

    }
    return 0;
}

