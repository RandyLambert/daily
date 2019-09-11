#include<bits/stdc++.h>//万能头文件 Orz
int n;
int h[100000];
int ans=0;

int main(){
      scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&h[i]);
        ans += h[i]-min(h[i],h[i-1]);
    }
    printf("%d",ans);

    return 0;
}
