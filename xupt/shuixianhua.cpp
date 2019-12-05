#include <stdio.h>
#define BEGIN 99
#define END 1000
int main()
{
	int start,end,a,b,c,d,x;
	int size=0;
	scanf("%d%d",&start,&end);
	if(BEGIN<start<=end<1000)
	{
		for(x=start;x<=end;x++)
		{
			a=(int)(x/100);
			b=(int)((x-100*a)/10);
			c=x-100*a-10*b;
			if(x==a*a*a+b*b*b+c*c*c)
			{
				printf("%d ",x);
				size++;
			}
			else
				continue;

		}
		if(size==0)
			printf("no");
	}
	return 0;
}

