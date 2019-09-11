#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int number;
    int score;
}aa[5005];
bool cmp(node a,node b){
    if(a.score == b.score){
        return a.number < b.number;
    }
    else{
        return a.score > b.score;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++){
        scanf("%d%d",&aa[i].number,&aa[i].score);
    }
    sort(aa,aa+n,cmp);
    int num = m*1.5;
    int temp = num - 1;
    while(aa[num - 1].score == aa[temp].score){
        temp++;
    }
    printf("%d %d\n",aa[temp-1].score,temp);
    for(int i = 0;i < temp;i++){
        printf("%d %d\n",aa[i].number,aa[i].score);
    }
    return 0;
}
