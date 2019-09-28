#include <bits/stdc++.h>
using namespace std;
struct node{
    int num,tim,per;
    bool operator < (const node &a)const
    {
        if(tim == a.tim)
        {
            return num > a.num;
        }
        else
        {
            return tim > a.tim;
        }
    }
};

priority_queue<node> q;

int main()
{
    string s;
    while(cin >> s && s!="#")
    {
        node a;
        cin>>a.num>>a.per;
        a.tim = a.per;
        q.push(a);
    }

    int k;
    cin>>k;
    while(k--)
    {
        node nw = q.top();
        q.pop();
        cout<<nw.num<<"\n";
        nw.tim+=nw.per;
        q.push(nw);
    }

    return 0;
}

