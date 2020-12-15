#include <bits/stdc++.h>
using namespace std;
int sale[1000][6];	//每个优惠中每个商品数量 
int price[1000];	//优惠总价 
int length[1000];	//优惠总共有几个商品 
int number[1000][1000];	//优惠商品的ID 
int shang[6][4];     //1 number   2 price  3 last num
int num[1000];		//商品ID 
int dp[6][6][6][6][6];	
int n,m;

int main()
{
    // 处理输入
    cin>>n;
    for(int i = 1; i  <= n; i++)
    {
        cin>>shang[i][1]>>shang[i][3]>>shang[i][2];
        num[i] = shang[i][1];
    }
    cin>>m;
    for(int i = 1; i <= m; i++)
    {
        cin>>length[i];
        for(int j = 1; j <= length[i]; j++)
        {
            cin>>number[i][j];
            cin>>sale[i][number[i][j]];
        }
        cin>>price[i];
    }

    dp[0][0][0][0][0] = 0;
    for(int i = 0; i <= shang[1][3]; i++)
        for(int j= 0; j <= shang[2][3]; j++)
            for(int k = 0; k <= shang[3][3] ;k++)
                for(int l = 0; l <= shang[4][3]; l++)
                    for(int p = 0; p <= shang[5][3]; p++)
                    {
                        int minx = i * shang[1][2] + j * shang[2][2] + k * shang[3][2] + l * shang[4][2] + p * shang[5][2];
                        for(int q = 1; q <= m; q++)
                        {
                            if(i -sale[q][num[1]]<0 || i - sale[q][num[2]]<0 ||	i-sale[q][num[3]]<0 || i-sale[q][num[4]]<0 ||i-sale[q][num[5]]<0)
                                continue;
                            int t = dp[i - sale[q][num[1]]][j - sale[q][num[2]]][k - sale[q][num[3]]][l - sale[q][num[4]]][p - sale[q][num[5]]] + price[q];

                            if(t < minx)
                                minx = t;
                        }

                        dp[i][j][k][l][p] = minx;
                    }

    cout<<dp[shang[1][3]][shang[2][3]][shang[3][3]][shang[4][3]][shang[5][3]]<<endl;
    return 0;
}
