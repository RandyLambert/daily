#include <bits/stdc++.h>
using namespace std;

int a[400][400];
int book[25];
char pot[25];
int n,m;
int num[25][3];

queue<int> q;
void dfs(int step)
{
	printf("%c",pot[step]);
	book[step] = 1;
	for(int i = 0;i < n;i++)
	{
		if(!book[i] && a[step][i])
		{
			dfs(i);
		}
	}
}

void bfs()
{
	
	printf("%c",pot[0]);
	book[0] = 1;
	q.push(0);

	while(!q.empty())
	{
		int temp = q.front();
		q.pop();

		int w = -1;

		for(int i = 0;i < n;i++)
		{
			if(a[temp][i] && !book[i])
			{
				w = i;
				break;
			}
		}
		while(w != -1)
		{
			if(!book[w])
			{
				printf("%c",pot[w]);
				book[w] = 1;
				q.push(w);
			}

			for(int i = w;i < n;i++)
			{
				if(a[temp][i] && !book[i])
				{
					w = i;
					break;
				}
				else w = -1;
			}
		}
	}
}



int main()
{
	scanf("%d%d",&n,&m);
	getchar();
	for(int i = 0;i < n;i++)
        scanf("%c",&pot[i]);
	getchar();
	for(int i = 0;i < m;i++)
	{
		char temp1,temp2;
		scanf("%c%c",&temp1,&temp2);
		getchar();
		a[temp1 - 'A'][temp2 - 'A'] = 1;
        num[temp1 - 'A'][0]++;
        num[temp2 - 'A'][1]++;
	}


	for(int i = 0;i < n;i++)
	{
		printf("%c %d %d %d\n",pot[i],num[i][0],num[i][1],num[i][0] + num[i][1]);
	}

	memset(book,0,sizeof(book));
	dfs(0);
	printf("\n");
	memset(book,0,sizeof(book));
	bfs();
	printf("\n");

	return 0;
}

