#include <bits/stdc++.h>
using namespace std;
int f[100006];
int book[100006];
int a,b;
int find(int x){
    if(f[x] == x){
        return x;
    }
    else{
        f[x] = find(f[x]);
        return f[x];
    }
}

int dggue(int x,int y){
    int fx = find(x);
    int fy = find(y);

    if(fx != fy){
        f[fy] = fx;
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    while(1){
        for(int i = 0;i <= 100001;i++){
            f[i] = i;
            book[i] = 0;
        }
        int xx = 0,nn = 1,mn=9999999,mx=-1,flag=0;
        while(scanf("%d%d",&a,&b)&&a!=0&&b!=0){
            xx++;
            if(a==-1&&b==-1){
                exit(0);
            }
			if(a>mx) mx=a;
			if(b>mx) mx=b;
			if(a<mn) mn=a;
			if(b<mn) mn=b;
            book[a]=1;
            book[b]=1;
            if(dggue(a,b)==0){
                nn = 0;
            }
        }
        if(xx==0&&a==0&&b==0)
        {
            printf("Yes\n");
            continue;
        }
        if(nn == 0){
            printf("No\n");
            continue;
        }
        for(int i = mn;i<=mx;i++)
        {
            if(book[i]==1&&f[i]==i){
                flag++;
            }
        }
        if(flag==1){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}
