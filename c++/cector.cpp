#include <iostream>
#include <vector>
#include<string>

int main(){
    std::vector<std::string> names;

    names.push_back("fuck you");
    names.push_back("hhhhhhh");

    std::vector<std::string>::iterator iter = names.begin();
    while(iter != names.end()){
        std::cout << *iter <<"\n";
        ++iter;
    }
    return 0;
}

