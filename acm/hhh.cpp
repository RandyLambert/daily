#include <bits/stdc++.h>
using namespace std;
long long int a[1000010],b[1000010];
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		long long int x = 0,y = 0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%d",&n);
		for(int i = 0;i < n;i++){
			scanf("%lld%lld",&a[i],&b[i]);
			x = x+b[i];
		}
		long long int z;
		for(int i = 0;i < n;i++){
			z = min(x-b[i],a[i]);
			y = z + y;
		}
		printf("%lld\n",min(x,y));
	}

	return 0;
}
