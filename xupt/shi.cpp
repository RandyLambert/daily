#include <bits/stdc++.h>
using namespace std;
typedef struct yuesefu{
    int data;
    struct yuesefu *Next;

    yuesefu(int da = 0):Next(this){
        data = da;
    }

    void inSert(yuesefu *b){
        yuesefu *tp;
        tp = Next;
        Next = b;
        b->Next = tp;
    }

    void poP(){
       Next = Next->Next;
    }

    void print(){
        cout<<data;
    }
}* List,Node;
int main(){

    yuesefu a;
    yuesefu b(1);
    yuesefu c(2);
    yuesefu d(3);
    yuesefu e(4);
    yuesefu f(5);
    yuesefu g(6);
    yuesefu h(7);
    yuesefu x(8);
    a.inSert(&b);
    b.inSert(&c);
    c.inSert(&d);

    for(int i = 0;i < 10;i++)
    {
        a.print();
    }    
    return 0;
}
