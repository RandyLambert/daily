#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y,mxx1 = 0,mxy1 = 0,mix1 = 12123,miy1 = 1312;
    int mx,my,mxx2 = 0,mxy2 = 0,mix2 = 12123,miy2 = 1312;
    for(int i = 0;i < 4;i++)
    {
        cin>>x>>y;
        mxx1 = max(mxx1,x);
        mxy1 = max(mxy1,y);
        mix1 = min(mix1,x);
        miy1 = min(miy1,y);

    }
    for(int i = 0;i < 4;i++)
    {
        cin>>x>>y;
        mxx2 = max(mxx2,x);
        mxy2 = max(mxy2,y);
        mix2 = min(mix2,x);
        miy2 = min(miy2,y);

    }
    mx = (mxx2+mix2)/2;
    my = (mxy2+miy2)/2;
    if(mxx2<=mxx1&&mxx2>=mix1&&mxy2<=mxy1&&mxy2>=miy1)
    {
        cout<<"YES"<<endl;
    }
    else if(mix2 <= mxx1 && mix2 >= mix1 && miy2 <= mxy1 && miy2 >= miy1)
    {
        cout<<"YES"<<endl;
    }
    else if(mix2 <= mxx1 && mix2 >= mix1 && my <= mxy1&&my >= miy1)
    {
        cout<<"YES"<<endl;
    }
    else if(mxx2 <= mxx1 && mxx2 >= mix1 && my <= mxy1 && my >= miy1)
    {
        cout<<"YES"<<endl;
    }
    else if(mxx1 + mxy1 <= mx)
    {

    }
    cout<<"NO"<<endl;

    return 0;
}
