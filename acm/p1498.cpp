#include <bits/stdc++.h>
using namespace std;
char a[4096][4096];
int main(){
    int n,x = 2048,y = 2;
    cin>>n;
    a[0][x-1] = '/',a[0][x]= '\\';
    a[1][x-2] = '/',a[1][x-1] = '_',a[1][x]='_',a[1][x+1]='\\';
    for(int i = 2;i <= n;i++){

        for(int j = y;j < y*2;j++){
            for(int k = x - y*2;k <= x-1;k++){
                a[j][k] = a[j-y][k+y];
            }
            for(int k = x;k <= x+y*2-1;k++){
                a[j][k] = a[j-y][k-y];
            }
        }
        y = y*2;
    }

    for(int i = 0;i < y;i++){
        for(int j = x-y;j < x+y;j++){
            if(!a[i][j])
                printf(" ");
            else
                printf("%c",a[i][j]);
        }
        putchar('\n');
    }


    return 0;
}

