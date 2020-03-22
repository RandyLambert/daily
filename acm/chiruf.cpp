#include <bits/stdc++.h>
using namespace std;
char txt[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char a[200005];
int main(){
    int n,m;
    char x1,x2;
    /* printf("%d",'a'-97); */
    scanf("%d%d",&n,&m);
    while(getchar()!='\n');
    scanf("%s",a);
    while(getchar()!='\n');
    while(m--){
        scanf("%c %c",&x1,&x2);
        while(getchar()!='\n');
        for(int i = 0;i < 26;i++){
            if(txt[i] == x1){
                txt[i] = x2;
            }
            else if(txt[i] == x2){
                txt[i] = x1;
            }
        }
    }
    int x = strlen(a);
    for(int i = 0;i < x;i++){
        printf("%c",txt[a[i]-97]);
    }


    return 0;
}

