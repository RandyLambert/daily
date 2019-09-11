#include <bits/stdc++.h>
using namespace std;
int text[100006];
int main(){
    int a,b,mx = -111,mi = 99999999,flag = 0;
    while(1){
        while(scanf("%d%d",&a,&b)&&a!=0&&b!=0){
            if(a==-1&&b==-1){
                exit(0);
            }
            text[a]++;
            text[b]++;
            mx = max(a,mx);
            mx = max(b,mx);
            mi = min(a,mi);
            mi = min(b,mi);
        }
        for(int i = mi;i <= mx;i++){
            if(text[i]!=0){
                if(text[i]%2==0)
                    flag = 1;
                printf("%d ",text[i]);
            }
        }    
        if(flag == 1)
            printf("No\n");
        else
            printf("Yes\n");
        memset(text,0,sizeof(text));
        flag = 0;
    }
    return 0;
}
