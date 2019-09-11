#include<cstdio>
#include<cstring>
int n,m,ans;
int a[510];
bool ch(int x)
{
    int su=0,an=0;//an表示能分几个人 
    //printf("%d\n",x);
    for(int i=n;i>=1;i--)
    {
        if(i==1) an++; //最后一人（最前面的）需要特殊处理 
        if(su+a[i]<=x)
        {
            su+=a[i];
        }
        else
        {
            an++;su=a[i];
        }
    }
    if(an<=m) return 1;
    return 0;
}
void pr(int l,int r) //打印当前左右边界内的部分 
{
    int ss=0;
    for(int i=r;i>=l;i--)
    {
        if(ss+a[i]>ans)
        {
            pr(l,i);
            printf("%d %d\n",i+1,r);//逆序输出，回溯时才打印 
            return ; 
        }
        ss+=a[i];
    }
    printf("%d %d\n",1,r);//关于第一个人的特殊处理（边界） 
}
int main()
{
    scanf("%d %d",&n,&m); if(n==0) return 0;// 判 0 的坑点，我wa了3次 
    int l=0,r,mid;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        r+=a[i]; 
    }
    // 二分模板
    while(l<=r)
    {
        mid=(l+r)/2;
        if(ch(mid))
        {
            ans=mid; //ans存的就是每个人能分到的页数最大值，用这个来判输出 
            r=mid-1;
        }
        else l=mid+1;
    }
    printf("%d\n",ans);
    //printf("%d\n",ans);
    pr(1,n);// 打印函数（我用递归来实现的，直接倒推打循环也是可以的） 
    return 0;
}
