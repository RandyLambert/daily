#include <bits/stdc++.h>
using namespace std;
int mp[9][9];
int vis1[3][3],vis2[9],vis3[9],n2[9] = {1,2,4,8,16,32,64,128,256};

bool judge(int n,int p,int i){
    i--;
    /* printf("%d %d %d",((vis1[n/3][p/3]>>i)&1),((vis2[n]>>i)&1),((vis3[p]>>i)&1)); */
    if(((vis1[n/3][p/3]>>i)&1) || ((vis2[n]>>i)&1) || ((vis3[p]>>i)&1)){
        return false;
    }
    else{
        return true;
    }

}
//n是行,p是列
void dfs(int n,int p){

    if(mp[n][p]!=0){

        if(n == 8 && p == 8){
            for(int i = 0;i < 9;i++){
                for(int j = 0;j < 9;j++){
                    printf("%d ",mp[i][j]);
                }
                putchar('\n');
            }
        }
        else if(p == 8){
            dfs(n+1,0);
        }
        else{
            dfs(n,p+1);
        }
    }
    else{
        for(int i = 1;i <= 9;i++){
            /* printf("%d %d\n",n,p); */
            if(judge(n,p,i)){
                mp[n][p] = i;
                vis1[n/3][n/3]+=n2[mp[n][p]-1];
                vis2[n]+=n2[mp[n][p]-1];
                vis3[p]+=n2[mp[n][p]-1];


                if(n==8 && p==8){
                    for(int ii = 0;ii < 9;ii++){
                        for(int j = 0;j < 9;j++){
                            printf("%c ",mp[ii][j]);
                        }
                        putchar('\n');
                    }
                }

                else if(p == 8)
                    dfs(n+1,0);
                else
                    dfs(n,p+1);
                /* mp[n][p] = 0; */
                /* vis1[n/3][p/3]-=n2[i-1]; */
                /* vis2[n]-=n2[i-1]; */
                /* vis3[p]-=n2[i-1]; */
            }
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(mp,0,sizeof(mp));
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        memset(vis3,0,sizeof(vis3));
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                scanf("%d",&mp[i][j]);
                if(mp[i][j]!=0){
                    vis1[i/3][j/3]+=n2[mp[i][j]-1];
                    vis2[i]+=n2[mp[i][j]-1];
                    vis3[j]+=n2[mp[i][j]-1];
                }
            }
        }
        dfs(0,0);
                    for(int ii = 0;ii < 9;ii++){
                        for(int j = 0;j < 9;j++){
                            printf("%d ",mp[ii][j]);
                        }
                        putchar('\n');
                    }
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                printf("%d ",vis1[i][j]);
            }
        putchar('\n');
        }
        for(int i = 0;i < 9;i++)
            printf("%d ",vis2[i]);
        putchar('\n');
        for(int i = 0;i < 9;i++)
            printf("%d ",vis3[i]);
        printf("%d\n",judge(1,1,8));
    }
    return 0;
}

