#include <bits/stdc++.h>
using namespace std;
int b[10002];
int main(){
    int a,a1 = 0,step = 0;
    scanf("%d",&a);
    for(int i = 0;i < a;i++){
        scanf("%d",&b[i]);
        a1 = a1 + b[i];
    }
    int md = a1/a;

    for(int i = 0;i < a-1;i++){
        if(b[i] != md){
            b[i+1] =b[i+1] - md + b[i];
            b[i] = md;
            step++;
        }
    }
    printf("%d",step);

    return 0;
}
