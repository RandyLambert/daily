#include <cstdio>
#include <cstring>
#define MAX 1002
int vist[MAX],map[MAX][MAX],degree[MAX];
int n,m;
void dfs(int cur){
	int i;
	vist[cur] = 1;
	for(i = 1; i <= n; i++)
		if(!vist[i] && map[i][cur] )
			dfs(i);
}
 
int main(){
	int i,a,b;
	int flag;
  	while( ~scanf("%d%d",&n,&m),n ){
		memset(degree,0,sizeof(degree));		
		memset(map,0,sizeof(map));
		memset(vist,0,sizeof(vist));
		for( i = 0; i < m; i++ ){
			scanf("%d%d",&a,&b);
			map[a][b] = map[b][a] = 1;
			degree[a]++;
			degree[b]++;
		}
		flag = 1;
		dfs(1);
		for( i = 1; i <= n; i++ ){
			if( degree[i] % 2 ){
				flag = 0;
				break;
			}
			if( !vist[i] ){
				flag = 0;
				break;
			}
		}
		if(flag)
			printf("1\n");
		else
			printf("0\n");
	}
    return 0;
}
