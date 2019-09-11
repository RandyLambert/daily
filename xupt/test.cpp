#include <iostream>
#include <stdio.h>
using namespace std;
int main(){

    unsigned char i = -1;
    /* cout<<i<<"\n"; */
    printf("%d\n",i);

    /* string a(0); */
    int b(0);
    cout<<b<<endl;
    int &c = b;
    b = 1;
    cout<<c<<b<<endl;
    getchar();
    return 0;
}

