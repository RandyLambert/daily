#include <thread>
#include <iostream>
using namespace std;
template<typename... Arg>
void syszuxPrint(Arg&&... arg){
    auto a = std::forward<Arg>(arg)...;
    //thread Thread = thread(std::forward<Arg>(arg)...);
    thread Thread = thread(a);
    Thread.join();
}

void func(int a,double b){
    cout<<a<<" "<<b;
}
int main(){
    
    syszuxPrint(func,1,33.2);
}

