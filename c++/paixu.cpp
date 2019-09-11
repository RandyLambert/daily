#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

int main(){
    std::vector<std::string> names;

    names.push_back("larry");
    names.push_back("hhhhhhh");
    names.push_back("xxhhh");
    names.push_back("aaahhhhh");
    names.push_back("ddadhhhashhhh");
    names.push_back("push_heaphh");
    names.push_back("uncaught_exceptionshhhh");
    names.push_back("dahahh");

        std::sort(names.begin(),names.end());

    std::vector<std::string>::iterator iter = names.begin();
    while(iter != names.end()){
        std::cout << *iter <<"\n";
        ++iter;
    }
    return 0;
}
