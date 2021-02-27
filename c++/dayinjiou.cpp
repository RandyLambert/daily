#include <bits/stdc++.h>
using namespace std;
class ZeroEvenOdd {
private:
    int n;
    int cnt;
    mutex mutexEven_;
    mutex mutexOdd_;
    condition_variable condEven_;
    condition_variable condOdd_;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        cnt = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(cnt != n){
            unique_mutex lock(mutexOdd_,);
            condOdd_.wait(mutex_, []{});
        }
    }

    void even(function<void(int)> printNumber) {
        if(n%2 == 0){
            while(n+=2)
        }
    }

    void odd(function<void(int)> printNumber) {
        
    }
};
