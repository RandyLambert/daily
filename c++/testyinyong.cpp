#include <iostream>
using namespace std;
int a(){
    static int c = 10;
    return c;
}

void b(int *x){
    x = (int *)malloc(sizeof(int));
    *x = 1000; 
    return ;
}
int main(){

    int f = 10;
    int &e = f;
    int &d = e;
    int *g = &f;
    b(g);
    cout<<e<<d<<f<<endl;
    cout<<*g<<endl;

    return 0;
}
