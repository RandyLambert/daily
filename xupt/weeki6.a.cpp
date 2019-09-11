#include <bits/stdc++.h>
using namespace std;
int main(){
    int flag = 0,mx,my,mxx2 = -105,mxy2 = -105,mix2 = 121,miy2 = 112;
    int x,y,mxx1 = -105,mxy1 = -105,mix1 = 121,miy1 = 121;
    for(int i = 0;i < 4;i++)
    {
        cin>>x>>y;
        mxx1 = max(mxx1,x);
        mxy1 = max(mxy1,y);
        mix1 = min(mix1,x);
        miy1 = min(miy1,y);

    }
    /* for(int  i = mix1;i <= mxx1 ;i++) */
    /* { */
    /*     for(int j = miy1;j <= mxy1;j++) */
    /*     { */
    /*         printf("%d %d",i,j); */
    /*     } */
    /*     putchar('\n'); */
    /* } */
    for(int i = 0;i < 4;i++)
    {
        cin>>x>>y;
        mxx2 = max(mxx2,x);
        mxy2 = max(mxy2,y);
        mix2 = min(mix2,x);
        miy2 = min(miy2,y);

    }
    int h = (mxx2-mix2)/2;
    int hh = h,yy = 0;
    //printf("mix2=%d mxx2=%d miy2=%d mxy2=%d\n",mix2,mxx2,miy2,mxy2);
    
    for(int i = mix2;i <= mxx2;i++)
    {   
        if(h>0){
            for(int j = miy2 + h;j <= mxy2 - h;j++)
            {
                if(i <= mxx1&&i >= mix1 && j <= mxy1 && j >= miy1)
                {
                    flag = 1;
                    break;
                }
                //printf("\ni=%d,j=%d\n",i,j);
            }
            h--;
        }
        else{
            for(int j = miy2 + yy;j <= mxy2 - yy;j++)
            {
                if(i <= mxx1&&i >= mix1 && j <= mxy1 && j >= miy1)
                {
                    flag = 1;
                    break;
                }
                //printf("\ni=%d,j=%d\n",i,j);
            }
            yy++;
        }

    }
    if(flag == 1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
