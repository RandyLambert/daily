#include <bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005],c[1000005];
int main(){
    int n = 0;
    while(scanf("%d",&a[n])&&a[n]!=0)
    {
        n++;
    }
    int cont = 0,cnt = 0;
    b[0] = a[0];
    c[0] = a[0];
    for(int i = 1;i < n;i++)
    {
        if(a[i] <= b[cnt])
        {
            b[++cnt] = a[i];
        }
        else
        {
            int wei = upper_bound(b,b+cnt,a[i],greater<int>()) - b;
            //printf("%d ",wei);
            b[wei] = a[i];
        }

        if(a[i] > c[cont])
        {
            c[++cont] = a[i];
        }
        else
        {
            int wei = lower_bound(c,c+cont,a[i]) - c;
            c[wei] = a[i];
        }
        /* printf("\n%d\n",c[0]); */
    }
    /* for(int i = 0;i <= cont;i++) */
    /* { */
    /*     printf("%d ",c[i]); */
    /* } */
    /* printf("cont = %d",cont); */
    printf("\n%d\n%d",cnt+1,cont+1);

    return 0;
}
