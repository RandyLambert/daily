#include <bits/stdc++.h>
using namespace std;
int a[300010],b[300010];
int main(){

    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m;i++){
        scanf("%d%d",&a[i],&b[i]);
    }

    int x = a[0],i = 1,cnt;
    while(i<m){
        if(a[i] == x || b[i] == x){
            i++;
        }
        else{
            break;
        }
    }
    cnt = i;
    while(i<m){
        i++;
        if(a[cnt] == a[i] || x == a[i] || a[cnt] == b[i] || x == b[i])
            continue;
        else
            break;
    }

    if(i == m){
        printf("YES\n");
        exit(0);
    }

    i = cnt;
    while(i<m){
        i++;
        if(b[cnt] == a[i] || x == a[i] || b[cnt] == b[i] || x == b[i])
            continue;
        else
            break;
    }


    if(i == m){
        printf("YES\n");
        exit(0);
    }

    x = b[0],i = 1;
    while(i<m){
        if(a[i] == x || b[i] == x){
            i++;
        }
        else{
            break;
        }
    }
    cnt = i;
    while(i<m){
        i++;
        if(a[cnt] == a[i] || x == a[i] || a[cnt] == b[i] || x == b[i])
            continue;
        else
            break;
    }


    if(i == m){
        printf("YES\n");
        exit(0);
    }

    i = cnt;
    while(i<m){
        i++;
        if(b[cnt] == a[i] || x == a[i] || b[cnt] == b[i] || x == b[i])
            continue;
        else
            break;
    }

    if(i == m){
        printf("YES\n");
        exit(0);
    }
    else{
        printf("NO\n");
    }
    return 0;
}
