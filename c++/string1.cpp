#include <iostream>
#include <string>
using namespace std;
int main()
{
    const char *a = "dasdsa";
    const char *b = a;
    string c;
    c.assign(a,4);
    cout << c <<endl;

    return 0;
}

