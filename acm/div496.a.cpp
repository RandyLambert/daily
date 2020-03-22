#include <bits/stdc++.h>
using namespace std;
int n;
int jilu[1005];
int main(){
    int temp[1005];
    scanf("%d",&n);
    int ci = 1;
    int step = 0;
    for(int i = 0;i < n;i++){
        scanf("%d",&temp[i]);
    }
    for(int i = 0;i < n-1;i++){
        if(temp[i] < temp[i+1]){
            ci++;
        }
        else{
            jilu[step] = ci;
            step++;
            ci = 1;
        }
    }
    step = step + 1;
    jilu[step-1] = ci;
    printf("%d\n",step);
    for(int i = 0;i < step;i++){
        printf("%d ",jilu[i]);
    }
    return 0;
}
