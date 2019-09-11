#include <bits/stdc++.h>
using namespace std;
char a[2000010],b[2000010];
int main(){
    scanf("%s%s",a,b);
    int a1 = strlen(a);
    int b1 = strlen(b);
    int step = 0;
    if(a[a1-1] != b[b1-1]){
        printf("%d\n",a1+b1);
        exit(0);
    }
    int i,j;
    /* while(1){ */
        /* if(a[i] = ) */
    /* } */
    for(i = a1-1,j = b1-1;i >= 0,j >= 0;i--,j--){
        if(a[i]==b[j]){
            step++;
        }
        else{
            break;
        }
    }
    printf("%d",a1+b1-step*2);
    return 0;
}
