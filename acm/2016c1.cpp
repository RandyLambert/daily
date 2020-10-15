#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double a[10];
int book[10],sum;
void fun(int step)
{
	int i;
	if(step==10)
	{
		if(a[1]+a[2]/a[3]+(a[4]*100+a[5]*10+a[6])/(a[7]*100+a[8]*10+a[9])==10)
			sum++;
		return;
	}
	for(i=1;i<=9;i++)
		if(book[i]==0)
		{
			a[step]=i;
			book[i]=1;
			fun(step+1);
			book[i]=0;
		}
	return;
} 
int main(int argc, char *argv[]) {
	fun(1);
	printf("%d",sum);	
	return 0;
} 
