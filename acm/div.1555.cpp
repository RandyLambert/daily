#include <bits/stdc++.h>

using namespace std;


int main(){
    int y,step = 0;
    scanf("%d",&y);
    y++;
    step++;
    while(y!=1){
        while(y%10!=0){
            y++;
            step++;
        }
        while(y%10==0)
            y = y/10;
        step--;
    }
    step = step + 8;
    printf("%d",step);
    return 0;
}
