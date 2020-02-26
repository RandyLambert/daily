#include <iostream>
#include <memory>
#include <vector>
int main(){

    std::vector<std::unique_ptr<int>> q;
    int *x = new int(1);
    q.push_back(new std::unique_ptr<int>(x));
    

    return 0;
}

