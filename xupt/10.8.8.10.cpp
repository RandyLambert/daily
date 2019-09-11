#include<bits/stdc++.h>
using namespace std;
	int main()
	{
		int y,m;
		cout << "1：十进制转换为八进制；2：八进制转换为十进制，请输入你要进行的转换类型："; cin >> y;
		cout << "请依次输入这个数的值："; cin >> m;
		int i, k = 0, a[30];
		switch (y)
		{
		case 1:
			while (m != 0)
			{
				a[k] = m % 8;
				k++;
				m = m / 8;
			}
			for (i = k - 1; i >= 0; i--)
			{
				cout << a[i];
			}
			cout << "则所转换的数值为：" << m << endl;
			break;
		case 2:
			while (m != 0)
			{
				a[k] = m % 10;
				k++;
				m = m / 10;
			}
			for (i = k - 1; i >= 0; i--)
			{
				cout << a[i];
			}
			cout << "则所转换的数值为：" << m << endl;
			break;
		}
	}

