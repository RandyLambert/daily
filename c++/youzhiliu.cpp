#include <bits/stdc++.h>
using namespace std;
void test(int&& xx){
    cout<<xx<<endl;
    xx = 1000;
}
void test(string&& xx){
    cout<<xx<<endl;
    xx = "1000";
}
int main()
{
    int xx = 10;
    test(std::move(xx));
    cout<<xx<<endl;

    string xxx = "10";
    string &&yy = std::move(xxx);
    cout<<xxx<<endl;
    cout<<yy<<endl;
    string z = std::forward<string&&>(yy);
    cout<<"tou"<<xxx<<endl;
    cout<<"tou"<<yy<<endl;

    test(std::move(xxx));
    cout<<xxx<<endl;

    return 0;
}
