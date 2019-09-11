#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define MAXN 110//开太大会内存超限
int dp[MAXN][MAXN];//dp[i][j]表示在i忍耐度下杀j只怪所得到的最多经验
int v[MAXN],w[MAXN];//分别表示杀掉一只这种怪xhd会得到的经验值和会减掉的忍耐度
 
int main()
{
    int n,m,K,s;
    while(cin>>n>>m>>K>>s)//还需的经验值 保留的忍耐度 怪的种数 最多的杀怪数
    {
        memset(dp,0,sizeof(dp));//初始化清空
        memset(v,0,sizeof(v));
        memset(w,0,sizeof(w));
        int i,j,k,flag=0;
        for(i=0; i<K; ++i)
            cin>>v[i]>>w[i];//可得到的经验值和会减掉的忍耐度
        for(i=1; i<=m; ++i)//忍耐度
        {
            for(j=0; j<K; ++j)//怪的种数
                for(k=1; k<=s; ++k) //可杀怪总数
                    if(w[j]<=i)
                        dp[i][k]=max(dp[i][k],dp[i-w[j]][k-1]+v[j]);
            if(dp[i][s]>=n)
            {
                cout<<m-i<<endl;
                flag=1;
                break;
            }
        }
        if(!flag)cout<<"-1"<<endl;
    }
    return 0;
}
