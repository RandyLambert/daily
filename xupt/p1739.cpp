#include <bits/stdc++.h>

using namespace std;

int main(){
    char a;
    int i = 0,flag = 0;
    while(1){
        scanf("%c",&a);
        if(a=='@')
            break;
        if(a == '('){
            i++;
        }
        else if(a == ')'){
            i--;
            if(i<0){
                flag = 1;
                break;
            }
        }
    }
    if(flag == 1 || i > 0){
        printf("NO");
    }
    else{
        printf("YES");
    }
    return 0;
}
