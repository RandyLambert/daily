#include <iostream>
#include <algorithm>
char a[105];
using namespace std;
int main(){
    int n,j = 0,mx = 0,i = 0;
    scanf("%d",&n);
    scanf("%s",a);
    while(i<n){
        if(a[i] == 'x'){
            j++;
            if(j == 3){
                j = 0;
                mx++;
                i = i-2;
            }
        }
        else{
            j = 0;
        }
        i++;
    }
    printf("%d",mx);
    return 0;
}
