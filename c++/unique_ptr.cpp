#include <iostream>
#include <memory>
#include <vector>
using namespace std;
int main(){

    std::vector<std::unique_ptr<int>> q;
    for(int i = 0;i < 10;i++)
    {
        std::unique_ptr<int> p(new int(i));
        q.push_back(std::move(p));
    }
    for(int i = 0;i < 10;i++){
        cout<<*q[i]<<endl;
    }
    /* q.push_back(new std::unique_ptr<int>(x)); */
    int *t = new int(1);
    q.push_back(unique_ptr<int>(t));
    

    return 0;
}

