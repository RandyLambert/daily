#include <iostream>
#include <memory>
#include <vector>
int main(){

    std::vector<std::unique_ptr<int>> q;
    int *x = new int(1);
    std::unique_ptr<int> p(new int(1));
    q.push_back(std::move(p));
    /* q.push_back(new std::unique_ptr<int>(x)); */
    

    return 0;
}

