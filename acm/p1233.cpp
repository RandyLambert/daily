#include<bits/stdc++.h>
using namespace std;
struct node{
	int kai;
	int jie;
}a[5005];

bool cmp(node a1,node b1){
    if(a1.kai == b1.kai ) return a1.jie > b1.jie;
    else return a1.kai > b1.kai;
}

bool vis[5002] = {0};

int main(){
	int n,step = 0,wi;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		scanf("%d%d",&a[i].kai,&a[i].jie);
	}
    
    sort(a,a+n,cmp);
	
    for(int i = 0;i < n;i++){
        if(vis[i] == 0){
            wi=a[i].jie;
            for(int j = i+1;j < n;j++){
                if(vis[j] == 0 && a[j].jie <= wi){
                    wi=a[j].jie;
                    vis[j] = 1;
                }
            } 
        }
    }
    for(int i = 0;i < n;i++)
        if(vis[i]==0) step++;
	printf("%d",step);
	return 0;
}

