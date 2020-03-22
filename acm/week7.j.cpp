#include <stdio.h>
const int xx = 10000;
struct node{
    long long int m[2][2]; 
}ans,tmp;
node cheng(node a,node b){
    node temp;
    temp.m[0][0] = (a.m[0][0]*b.m[0][0] + a.m[0][1]*b.m[1][0])%xx;
    temp.m[0][1] = (a.m[0][0]*b.m[0][1] + a.m[0][1]*b.m[1][1])%xx;
    temp.m[1][0] = (a.m[1][0]*b.m[0][0] + a.m[1][1]*b.m[1][0])%xx;
    temp.m[1][1] = (a.m[1][0]*b.m[0][1] + a.m[1][1]*b.m[1][1])%xx;
    return temp;
}
void kuaisu(int n){
    n=n-1;
    tmp.m[0][0] = tmp.m[0][1] = tmp.m[1][0]=1;
    tmp.m[1][1] = 0;
    ans.m[0][0] = ans.m[1][1] = 1,ans.m[1][0] = ans.m[0][1] = 0;
    while(n)
    {
        if(n&1)
        {
            ans = cheng(tmp,ans);
        }
        tmp = cheng(tmp,tmp);
        n = n>>1;
    }
    printf("%lld\n",ans.m[0][1]%xx+ans.m[0][0]);
}
int main(){
    int n = 1;
    scanf("%d",&n);
        if(n==1)
        {
            printf("1\n");
        }
        else if(n==2)
        {
            printf("2\n");
        }
        else
        {
            kuaisu(n);
        }
    
    return 0;
}
