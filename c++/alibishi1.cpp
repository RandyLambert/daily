#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll aa[200010],sub[200010];
vector<ll> bb;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>aa[i];
	for(ll i=0;i<=1e5;i++)
		bb.push_back(i*i);
	for(int i=1;i<=n;i++)
	{
		int indx=lower_bound(bb.begin(),bb.end(),aa[i])-bb.begin();
		sub[i]=min(abs(aa[i]-bb[indx]),abs(aa[i]-bb[indx-1]));
	}
	sort(sub+1,sub+1+n);
	ll ans=0;
	for(int i=1;i<=n/2;i++)
		ans+=sub[i];
	cout<<ans<<endl; 
 }