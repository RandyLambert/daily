#include<iostream> 
#include<cstdio>
#define LL long long 
using namespace std; 
LL num,ans=0,stack[800090],tot=0,n;//数组模拟栈 
int main() { cin>>n; for(int i=1;i<=n;i++) { cin>>num; while(tot>=1&&stack[tot]<=num) { tot--; } ans+=tot; stack[++tot]=num; } cout<<ans; return 0; }
