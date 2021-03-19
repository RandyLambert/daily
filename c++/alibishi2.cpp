#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll aa[3010],val[3010];
int main()
{
	int n;
	ll ans=300010;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>aa[i];
	for(int i=1;i<=n;i++)
		cin>>val[i];
	for(int i=1;i<=n;i++)
	{
		vector<ll> bb;
		ll maxn=aa[i];
		bb.push_back(val[i]);
		for(int j=i+1;j<=n;j++)
			if(aa[j]>maxn)
			{
				bb.push_back(val[j]);
				maxn=val[j];
			}
		sort(bb.begin(),bb.end());
		if(bb.size()<3)
			continue;
		else
			ans=min(ans,bb[0]+bb[1]+bb[2]);
	 } 
	if(ans==300010)
	 	cout<<-1<<endl;
	else 
		cout<<ans<<endl;
 }