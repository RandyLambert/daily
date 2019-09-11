#include <bits/stdc++.h>
using namespace std;
struct node{
    int a;
    int b;
}text[100005];
bool cmp(node x,node y){
    return ((x.a - x.b)>(y.a - y.b));
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++){
        scanf("%d%d",&text[i].a,&text[i].b);
    }
    
    sort(text,text+n,cmp);
    long long int sum1 = 0;
    long long int sum2 = 0;
    int xx = 0;
    for(int i = 0;i < n;i++){
        sum1 = sum1 + text[i].b;
        sum2 += text[i].a;
    }
    if(sum1 > m){
        printf("-1\n");
    }
    else{
        for(int i = 0;i < n;i++){
            if(sum2 > m){
                sum2 = sum2 - (text[i].a - text[i].b);
                xx++;
            }
        }
        printf("%d\n",xx);
    }

    return 0;
}
