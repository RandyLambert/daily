#include <iostream>
#include <string>
#include <mutex>
#include <condition_variable>
#include <thread>
using namespace std;
mutex m1;
condition_variable cv1;
mutex m2;
condition_variable cv2;
int i = 0;
int j = 0;
char s[30] = {"abcdefjhigklmnopqrstuvwxyz\0"};
void f1(){
    while(1){
        unique_lock<mutex> lock(m1);
        cv1.wait(lock,[]{ return i%2 == 0;});
        cout<<s[i]<<endl;
        i++;
        if(i == 25){
            lock.unlock();
            cv1.notify_one();
            break;
        } else{
            lock.unlock();
            cv1.notify_one();
        }
    }
}

void f2(){
    while(1){
        unique_lock<mutex> lock(m1);
        cv1.wait(lock,[]{ return i%2==1;});
        cout<<s[i]<<endl;
        i++;
        if(i == 26){
            lock.unlock();
            cv1.notify_one();
            break;
        } else{
            lock.unlock();
            cv1.notify_one();
        }
    }
}

int main()
{
    thread t1(f1);
    thread t2(f2);
    
    t1.join();
    t2.join();

    return 0;
}
