#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
int main(){
    string a("4324");
    cout<<*a.begin()<<a.front()<<endl;
    int *c = new int;

    char x[10] = "dd";
    const char xx = x[0];


    return 0;
}
