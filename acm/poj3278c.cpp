#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int maxsize = 100000;
const int MaxN = 1000000;
struct Step{
	int x;
	int step;
	Step(int xx,int s):x(xx),step(s) {}
};
int visited[MaxN];
int N,K;
queue <Step> q;
void BFS(int x,int step){
	q.push(Step(x,step));
	visited[x] = 1;
	while(!q.empty()){
		Step temp = q.front();
		if(temp.x == K){
			printf("%d\n",temp.step);
			return ;
		}else{
			if(!visited[temp.x + 1] && temp.x + 1 <= maxsize){
				visited[temp.x + 1] = 1;
				q.push(Step(temp.x + 1,temp.step+1));
			}
			if(!visited[temp.x-1] && temp.x-1 >= 0){
				visited[temp.x - 1] = 1;
				q.push(Step(temp.x - 1,temp.step+1));
			}
			if(!visited[2 * temp.x] && 2 * temp.x <= maxsize){
				visited[2 * temp.x] = 1;
				q.push(Step(2 * temp.x,temp.step + 1));
			}
			q.pop();
		}	
	}	
}
int main(){
	scanf("%d%d",&N,&K);
	memset(visited,0,sizeof(visited));
	BFS(N,0);
	return 0;
}
