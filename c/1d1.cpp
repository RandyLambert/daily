#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAX = 1000 + 10;
typedef struct node{
	int x;
	int y;	
}Node;

Node a[MAX];
Node b[MAX];
Node c[MAX];
int cmp(Node a,Node b)
{
	return a.y < b.y; 
}

int main()
{
	int n,m;
	scanf("%d",&n);
	
	getchar();
	for(int i = 1;i <= n;i++)
	{
		scanf("(%d,%d)",&a[i].x,&a[i].y);
	}
	
	scanf("%d",&m);
	
	getchar();
	
	for(int i = 1;i <= m;i++)
	{
		scanf("(%d,%d)",&b[i].x,&b[i].y);
	}
	
	int temp1 = 1;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			c[temp1].x = a[i].x * b[j].x;
			if(a[i].y == 0 || b[j].y == 0)
			{
				c[temp1].y = max(a[i].y,b[j].y);
				temp1++;
				continue; 
			}
			c[temp1].y=  a[i].y + b[j].y;
			temp1++;	
		}
	}
	sort(c + 1,c + temp1 + 1,cmp);
	int flag2 = 1;
	for(int i = 1;i <= temp1;i++)
	{
		if(c[i].y == 0) continue;
		if(c[i].y == c[i+1].y)
		{

			c[i].x = c[i].x + c[i+1].x;
			c[i+1].y = 0;
			c[i+1].x = 0;
			i--;
			sort(c + 1,c + temp1 + 1,cmp);
		}
	}

	int sum1 = 0;
	for(int i = 1;i <= temp1;i++)
	{
		if(c[i].y == 0)  
		{
			sum1 += c[i].x;
			c[i].x = 0;
		}
	}

	c[temp1 + 1].x = sum1;
	c[temp1 + 1].y = 0;
	
	sort(c + 1,c + temp1 + 1 + 1,cmp);
	int flag = 0;
	int flag1 = 0;
	for(int i = 1;i <= temp1 + 1;i++)
	{
		if(flag == 0)
		{
			{
				if(c[i].x == 0)  continue;
				flag = 1;
				flag1++;
				if(c[i].y == 1)
				{
					if(c[i].x == 1)
						printf("X");
					else if(c[i].x == -1)
						printf("-X");
					else
 						printf("%dX",c[i].x);
				}			
				else if(c[i].y != 0)
				{
					if(c[i].x == 1)
						printf("X^%d",c[i].y);
					else if(c[i].x == -1)
						printf("-X^%d",c[i].y);
					else 
						printf("%dX^%d",c[i].x,c[i].y);
				}
				else
				{
					printf("%d",c[i].x);
				}
			}
		}
		else
		{
			if(c[i].x > 0)
			{
					flag1++;
				if(c[i].y == 1)
				{
					if(c[i].x != 1)
 						printf("+%dX",c[i].x);
					else printf("X");
				}	
				else if(c[i].y != 0)
				{
					if(c[i].x != 1)
					{
						flag1++;
						printf("+%dX^%d",c[i].x,c[i].y);
					}
					else
					{
						printf("+X^%d",c[i].y);
						flag1++;
				
					}
				}
				else
				{
					flag1++;
					printf("+%d",c[i].x);
				}
			}
			else if(c[i].x < 0)
			{
				if(c[i].y == 1)
				{
					flag1++;
					if(c[i].x != -1)
						printf("%dX",c[i].x);
					else 
						printf("-X");
				}			
				else if(c[i].y != 0)
				{
					flag1++;
					if(c[i].x != -1)
						printf("%dX^%d",c[i].x,c[i].y);
					else printf("-X^%d",c[i].y);
				}
				else
				{
					flag1++;
					printf("%d",c[i].x);
				}
			}
			
		}	
	}
	if(flag1 == 0)  printf("0");
	printf("\n");
	
	
	return 0;
}

