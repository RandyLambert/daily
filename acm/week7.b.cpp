#include <bits/stdc++.h>
using namespace std;
int t,nex[2005];
//dp[2005][2005];
int dp[501];
char a[2005][2005];

inline void getnext(char b[]){
    int d = strlen(b);
    nex[0] = -1;
    int k = -1;
    int j = 0;
    while(j < d - 1){
        if(k == -1||b[k] == b[j]){
            k++;
            j++;
            nex[j] = k;
        }
        else{
            k = nex[k];
        }
    }
}

inline int kmp(char a[],char b[]){
    int al = strlen(a);
    int bl = strlen(b);
    int i=0,j=0;
    getnext(b);

    while(al>i && bl>j){
        if(j == -1||a[i] == b[j]){
            i++;
            j++;

        }
        else{
            j = nex[j];
        }
    }
    if(j == bl){
        return 1;
    }
    else{
        return -1;
    }
}

int main(){
    int n;
    scanf("%d",&t);
    for(int i = 1;i <= t;i++)
    {
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        int flag = 0,mx = 0;
        scanf("%d",&n);
        for(int j = 0;j < n;j++)
        {
            scanf("%s",&a[j]);
        }
        for(int j = 0;j < n-1;j++)
        {
            /* for(int k = n-1;k >= j;k++) */
            /* { */
                memset(nex,0,sizeof(nex));
                int x = kmp(a[j+1],a[j]);
                /* printf("x = %d\n",x); */
                dp[j] = x;
                if(x==-1)
                    mx = max(mx,j);
                /* if(x == -1){ */
                /*     flag = 1; */
                /*     printf("Case #%d: %d\n",i,j+1); */
                /*     break; */
                /* } */
                /*memset(dp,0,sizeof(dp));
                int len1 = strlen(a[j]);
                int len2 = strlen(a[k]);
                for(int g = 1;g <= len1;g++)
                {
                    for(int h = 1;h <= len2;h++)
                    {
                        if(a[j][g-1] == a[k][h-1])
                        {
                            dp[g][h] = max(dp[g][h],dp[g-1][h-1]+1);
                        }
                        else
                        {
                            dp[g][h] = max(dp[g-1][h],dp[g][h-1]);
                        }
                    }
                }
                if(dp[len1][len2]==len2)
                {
                    continue;
                }
                else{
                    flag = 1;
                    printf("%d\n",j+1);
                    break;
                }*/
            /* } */
            /* if(flag==1) */
            /*     break; */
        }
        /* if(flag==0) */
        /*     printf("Case #%d: -1\n",i); */
        for(int j = n-1;j >= 1;j--)
        {
            for(int k = j-1;k >= 1;k--)
            {
                if(dp[k]==-1)
                {
                    memset(nex,0,sizeof(nex));
                    int x = kmp(a[j],a[k]);
    //                printf(" \n%d %d\n",j,k);
                    if(x == -1)
                    {
                        flag = 1;
                        /* printf("%s\n",a[k]); */
                        printf("Case #%d: %d\n",i,j+1);
                        break;
                    }
                }
            }
            if(flag==1)
                break;
        }
        if(flag==0&&mx==0)
            printf("Case #%d: -1\n",i);
        else if(flag == 0&&mx!=0)
            printf("Case #%d: %d\n",i,mx+2);
    }
    return 0;
}
