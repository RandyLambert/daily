#include <bits/stdc++.h>
using namespace std;
char a[55],b[55];
int text[10005];
int main(){
    int n,sum;
    scanf("%d",&n);
    scanf("%s",a);
    scanf("%s",b);
    for(int i = 0;i < n;i++){
        if(a[i]!=b[i]){
            sum++;
        }
    }
    if(sum == 1){
        printf("-1\n");
    }
    else{
        char t;
        int boot = 0;
        while(1){
            int ci = 0;
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n-1-i;j++){
                    if(a[j] != b[j]){
                        t = a[j];
                        a[j] = a[j+1];
                        a[j+1] = t;
                        text[boot] = j+1;
                        boot++;
                        ci++;
                    }
                }
            }
            if(ci == 1){
                printf("-1\n");
                break;
            }
            else if(ci == 0){
                printf("%d\n",boot);
                for(int i = 0;i < boot;i++){
                    printf("%d ",text[i]);
                }
                putchar('\n');
                break;
            }
        }
    }
    return 0;
}
