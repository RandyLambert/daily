#include<bits/stdc++.h>
using namespace std;
int a[300001],b[300001];
int main(){
	int n,m;
	long long int sum = 0;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
		sum = sum + a[i];
	}
	sort(a,a+n);
	scanf("%d",&m);
	for(int i = 0;i < m;i++){
		scanf("%d",&b[i]);
	}
	
	int h = 0;
	while(h<m){
		sum = sum - a[n-b[h]];
		printf("%lld\n",sum);
		h++;
		sum = 0;
	}
	
	return 0;
}
