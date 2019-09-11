#include<iostream>
#include<string>
#include<vector>

int main(){
    std::vector<std::string>names;
    names.push_back("小甲鱼");
    names.push_back("xaoyouyx");

    for(size_t i = 0;i<names.size();i++){
        std::cout <<names[i]<<"\n";
    }
    return 0;
}
