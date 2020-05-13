#include <iostream>
#include <string>
using namespace std;
int main()
{
    char a[1024];
    sprintf(a,"dasdsada");
    string b(a);
    cout<<" "<<b<<endl;
    sprintf(a,"xxxxxxdasdsada");
    b = a;
    cout<<" "<<b<<endl;
    
    return 0;
}

