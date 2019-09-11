#include<bits/stdc++.h>

using namespace std;
int a[105];
int main()
{
	int n;
	int i;
	int flag = 1;
	int flag2 = 1;
	scanf("%d",&n);
	n +=1;
	for(i = 1;i <= n;i++)
	{
		//读取系数 
		scanf("%d",&a[i]);	
	}	
	for(i = 1;i <= n-1;i++)
	{
		if(a[i] != 0)
		{
			flag2 = 0;
		 } 
	}
	for(i = 1;i <= n-1;i++)
	{	
		if(a[i] == 0)
		{
			continue;
		}
		else if(flag == 1)
		{
			if(flag == 1)
			{
				flag++;
				if(a[i] == 1)
					{
						if(n-i == 1)
							printf("x",a[i]);
						else
							printf("x^%d",n-i);
					}
				else if(a[i] == -1) 
					if(n-i == 1)
						printf("-x");
					else
						printf("-x^%d",n-i);
				else
				{
					if(n-i == 1) printf("%dx",a[i]);
					else printf("%dx^%d",a[i],n-i); 
				} 
			}
			continue;
		}
			//第二项开始 
			if(a[i] < 0)
				{
					if(a[i] == -1)
						{
							if(n-i == 1)
								printf("-x",a[i]);
							else
								printf("-x^%d",n-i);
						}
					else
						if(n-i == 1)
							printf("%dx",a[i]);
						else
							printf("%dx^%d",a[i],n-i);
				}
			else
				{
					if(a[i] > 0)
					{
						if(a[i] == 1)
						{
							if(n-i == 1)
								printf("+x");
							else
								printf("+x^%d",n-i);		
						}
						else
						{
							if(n-i == 1)  printf("+%dx",a[i]);
							else printf("+%dx^%d",a[i],n-i);
						}
					}
				}
			}
			

	if(flag2 == 1)
	{
		if(a[n] == 0)
		{
			printf("0");
		}
		else //if(a[n] > 0)
		{
			printf("%d",a[n]);
		}
	}
	else 
	{
		if(a[n] == 0)
		{
			;
		}
		else if(a[n] > 0)
		{
			printf("+%d",a[n]);
		}
		else
		{
			printf("%d",a[n]);
		}
	}
} 
