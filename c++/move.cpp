#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a("dsdas");
    string b = std::move(a);
    cout<<a<<" "<<b<<endl;
    return 0;
}

