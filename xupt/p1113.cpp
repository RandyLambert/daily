#include<bits/stdc++.h>
using namespace std;
vector<int>q[10005];
queue<int>qq;
int len[10005],ru[10005],ans[10005],dp[10005];
int main(){
	int n,num,tmp,xx=1,cnt = 0;
    int sss = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		tmp=1;
		scanf("%d%d",&num,&len[i]);
		while(scanf("%d",&tmp)&&tmp!=0)
		{
			q[num].push_back(tmp);
			ru[num]++;
		}
	}
	qq.push(1);
	while(!qq.empty())
	{
		int temp = qq.front();
		ans[xx++] = temp;
		qq.pop();
		for(size_t i = 0;i < q[temp].size();i++)
		{
			if(ru[q[temp][i]]>=1)
			{
				ru[q[temp][i]]--;
				if(ru[q[temp][i]]==0)
				{
					qq.push(q[temp][i]);
				}
			}
		}
	}
    for(int i = 1;i <= n;i++)
        dp[i]=len[i];
	for(int i = 2;i <= n;i++){
        cnt = 0;
        for(size_t j = 0;j < q[i].size();j++){
            cnt = max(dp[q[i][j]],cnt);
            /* printf("%d\n",q[i][j]); */
        }
        /* putchar('\n'); */
	    /* printf("%d ",len[i]); */
        dp[i] = cnt + dp[i];
        sss = max(sss,dp[i]);
	}
    /* for(int i = 1;i <= n;i++ ) */
        printf("%d",sss);
	 /* printf("%d ",dp[n]); */ 
	return 0;
}
