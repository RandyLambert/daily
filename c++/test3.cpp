#include <iostream>
#include <thread>
#include <windows.h>
#include <condition_variable>
using namespace std;
std::mutex Full;
std::mutex Empty;
int value = 0;
int maxValue = 100;
std::condition_variable cvFull;
std::condition_variable cvEmpty;

void produce(){
    while(1){
        sleep(1);
        std::unique_lock<mutex> lock(Full);
        cvFull.wait(lock,[]{if(value < maxValue) return true; });
        value++;
        cout<<value<<endl;
        lock.unlock();
        cvEmpty.conify_one();
    }
}

void consume(){
    while(1){
        sleep(1);
        unique_lock<mutex> lock(Empty);
        cvEmpty.wait(lock,[]{if(value > 0) return true; });
        value--;
        cout<<value<<endl;
        lock.unlock();
        cvFull.conify_one();
    }
    

}
int main() {

    std::thread t1(produce);
    std::thread t2(consume);
    t1.join();
    t2.join();

    return 0;
}