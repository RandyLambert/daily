#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
}tmp[20000],tmp1[20000],ans[20000],ans1[20000];

bool cmp(node a1,node b1){
	return a1.b < b1.b;
}
int main()
{
	int n,n1,n2;
	char x,y,z;
	cin>>n1;
	
	for(int i = 0;i < n1;i++){
		cin>>x>>tmp[i].a>>z>>tmp[i].b>>y;
	}
	
	cin>>n2;
	for(int i = 0;i < n2;i++){
		cin>>x>>tmp1[i].a>>z>>tmp1[i].b>>y;
	}
	
	n = n1+n2;
	
	
	int cnt = 0;

	for(int i = 0;i < n1;i++){
		for(int j = 0;j < n2;j++){
			ans1[cnt].a = tmp[i].a*tmp1[j].a;
			ans1[cnt].b = tmp[i].b + tmp1[j].b;
			cnt++;
		}
	}
	
	sort(ans1,ans1+n,cmp);
	int cnt1 = 0;
	ans[0].a = ans1[0].a,ans[0].b = ans1[0].b;
	for(int i = 1;i < cnt;i++)
	{
		if(ans[cnt1].b == ans1[i].b)
		{
			ans[cnt1].a+=ans1[i].a;
		}
		else{
			cnt1++;
			ans[cnt1].a = ans1[i].a;
			ans[cnt1].b = ans1[i].b;
		}
	}
	
	/*for(int i = 0;i <= cnt;i++)
	{
		cout<<ans[i].a<<" "<<ans[i].b<<endl;
	}*/
	
	for(int i = 0;i <= cnt1;i++){
		
		if(i==0){
			if(ans[i].b==0){
				if(ans[i].a > 0)
					cout<<ans[i].a;
			}
			else if(ans[i].b == 1){
				cout<<ans[i].a<<"X";
			}
			else{
				cout<<ans[i].a<<"X^"<<ans[i].b;
			}
		}
		else{
			if(ans[i].b==0){
				if(ans[i].a>0)
					cout<<'+'<<ans[i].a;
				else if(ans[i].a<0)
					cout<<ans[i].a;
			}
			else if(ans[i].b == 1){
				if(ans[i].a>0)
					cout<<'+'<<ans[i].a<<"X";
				else if(ans[i].a<0)
					cout<<ans[i].a<<"X";
			}
			else{
				if(ans[i].a>0)
					cout<<'+'<<ans[i].a<<"X^"<<ans[i].b;
				else if(ans[i].a<0)
					cout<<ans[i].a<<"X^"<<ans[i].b;
			}
		}		
	}
	putchar('\n');
	
	return 0;
}

