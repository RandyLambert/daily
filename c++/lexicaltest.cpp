#include <iostream>
#include <boost/lexical_cast.hpp>
using namespace std;
int main()
{
    string a = "1223";
    size_t c = boost::lexical_cast<size_t>(a);
    cout<<++c<<endl;
    return 0;
}

