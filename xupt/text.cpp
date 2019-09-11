#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
long long book[200000+10];
long long arr[200000+10];
int m,n;
int main()
{
	map<long long,long long>mp;
	cin >> m;
	long long sum=0;
	for(int i=1;i<=m;i++)
	{
		cin >> book[i];
		sum+=book[i];
		mp[book[i]]++;
	}
	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		if((sum-book[i])%2==0)
		{
			mp[book[i]]--;
			if(mp[(sum-book[i])/2])
			arr[ans++]=i;
			mp[book[i]]++;
		}
	}
	printf("%lld\n",ans);
	for(int i=0;i<ans;i++)
	printf("%lld ",arr[i]);
	return 0;
}

