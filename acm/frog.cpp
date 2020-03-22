#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
ll fibo[210];
 
int lt[300], rt[300];
 
int main()
{
	//freopen("in.txt", "r", stdin);
	ll m;
	fibo[1] = 1;
	fibo[2] = 2;
	for(int i = 3; i <= 210; ++ i)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}	
	
	while(cin >> m)
	{
		int cnt = 50;
		int res = 1;
		int top = 0;
		if(m == 0)   //注意还要特判一下，因为答案个数必须要大于一
		{
			cout << 2 << endl << 1 << ' ' << 1 << endl << 2 << ' ' << 1 << endl;
			continue;
		}
		while(m)
		{
			while(fibo[cnt] > m)
			{
				cnt --;
			}
		    lt[top] = res;
			rt[top++] = 200 - cnt;
			res += 2;
			m -= fibo[cnt];
		}
		lt[top] = res - 1;
		rt[top++] = res - 1;
		cout << top << endl;
		for(int i = 0; i < top; ++ i)
		{
			cout << lt[i] << ' ' << rt[i] << endl;
		}
	}
 
	return 0;
}

