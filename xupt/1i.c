#include <stdio.h>                                                                    
int main ()
{
    int i,j,k,l,n,m,x,y,z;
    while(scanf("%d%d",&m,&n)==2)
    {        k=0;
        for(i=m;i<=n;i++)
        {
            x=i%10;
            y=i%100/10;
            z=i/100;
            if(x*x*x+y*y*y+z*z*z==i)
            {  
                if(k==0)
                {
                    printf("%d",i);                                     
                    k++;
                }
                else
                    printf(" %d",i);
            }
        }

        if(k==0)
            printf("no");
        printf("\n");
    }
}             

