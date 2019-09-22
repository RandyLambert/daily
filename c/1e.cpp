#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
}tmp[20000],ans[20000];

bool cmp(node a1,node b1){
	return a1.b < b1.b;
}
int main()
{
	int n,flag = 0;
	char x,y,z;
	cin>>n;
	
	for(int i = 0;i < n;i++){
		cin>>x>>tmp[i].a>>z>>tmp[i].b>>y;
	}
	
	
	int cnt = 0;

	sort(ans,ans+n,cmp);
	ans[0].a = tmp[0].a,ans[0].b = tmp[0].b;
	for(int i = 1;i < n;i++)
	{
		if(ans[cnt].b == tmp[i].b)
		{
			ans[cnt].a+=tmp[i].a;
		}
		else{
			cnt++;
			ans[cnt].a = tmp[i].a;
			ans[cnt].b = tmp[i].b;
		}
	}

    if(ans[0].b == 0){
        flag = 1;
    }
    for(int i = 0;i <= cnt;i++){
        
        ans[i].a = ans[i].b*ans[i].a;
        ans[i].b--;
    }


    /* for(int i = 0;i <= cnt;i++) */
    /* { */
    /*     da = da + int((double)ans[i].a *(pow((double)(ci),(double)(ans[i].b)))); */  
    /* } */
    /* cout<<da; */
	
	/* for(int i = 0;i <= cnt;i++) */
	/* { */
	/* 	cout<<ans[i].a<<" "<<ans[i].b<<endl; */
	/* } */
	
	for(int i = flag;i <= cnt;i++){
		
		if(i==flag){
			if(ans[i].b==0){
				if(ans[i].a > 0)
					cout<<ans[i].a;
			}
			else if(ans[i].b == 1){
				cout<<ans[i].a<<"X";
			}
			else if(ans[i].b > 1){
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
			else if(ans[i].b > 1){
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

