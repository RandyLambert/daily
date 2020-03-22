#include<bits/stdc++.h>

using namespace std;

struct node {
    int bi;
    int mi;
}b[1000001];

bool cmp(const node a,const node b){
    if(a.mi == b.mi){
        return a.bi > b.bi;
    }
    else{
        return a.mi < b.mi;
    }
}
int main(){
    int n,sum = 1;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d%d",&b[i].bi,&b[i].mi);
    }
    sort(b,b+n,cmp);

    int time;
    time=b[0].mi;
    for(int j=1;j<=n;j++){
        if(b[j].bi>=time){
            sum++;
            time=b[j].mi;
        }
    }
    printf("%d",sum);
    return 0;
}
