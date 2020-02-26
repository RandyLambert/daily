#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> a;
    /* a.reserve(100); */
    for(int i = 0;i < 10;i++)
        a.push_back(i);
    cout << a[1]<<endl;
    /* a.resize(50); */
    cout << a.capacity()<<endl;
    a.shrink_to_fit();
    cout << a.capacity()<<endl;

    return 0;
}

