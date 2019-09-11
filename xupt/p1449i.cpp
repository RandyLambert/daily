#include<stack>
#include<iostream>
#include<cstdio>
using namespace std;
stack<int> n;
char c;
int s,x,y;
int main()
{
    while(c!='@')
    {
        c=getchar();
        if(c=='+'){x=n.top(); n.pop(); y=n.top(); n.pop(); n.push(x+y); }
        else
        {
            if(c=='-'){x=n.top(); n.pop(); y=n.top(); n.pop(); n.push(y-x);}
            else
            {
                if(c=='*'){x=n.top(); n.pop(); y=n.top(); n.pop(); n.push(x*y); }
                else
                {
                    if(c=='/'){x=n.top(); n.pop(); y=n.top(); n.pop(); n.push(y/x); }
                    else
                    {
                        if(c=='.'){n.push(s); s=0;}
                        else{
                            s=s*10+c-'0';
                        }
                    }
                }
            }
        }
    }
    printf("%d",n.top());
    return 0;
}
