#include <iostream>
#include <map>
#include <string>
#include "fan.h"
using namespace std;

template<class T>
T getMapAs(map<string,string> m,T a)
{
    return getAs(m,a);
}
int main()
{
    map<string,string> a;
    int x = getMapAs<int>(a,10);
    cout<<x<<endl;

    return 0;
}

