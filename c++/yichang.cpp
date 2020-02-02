#include <iostream>
using namespace std;
void func()  //c++17已经不允许规定只能跑出int的异常
{
    throw(1);
}
int main(){
    //异常必须处理，不处理程序就直接退出了，catch...不得已而为之
    //栈解旋 到throw抛出异常之前 所有栈上的对象都会被释放 这个过程叫做栈解旋
    //构造和析构的顺序相反
    double m, n;
    cin >> m >> n;
    try {
        cout << "before dividing." << endl;
        if (n == 0)
            throw - 1;  //抛出整型异常
        else if (m == 0)
            throw - 1.0;  //拋出 double 型异常
        else
            cout << m / n << endl;
        cout << "after dividing." << endl;
    }
    catch (double d) {
        cout << "catch (double)" << d << endl;
    }
    catch (...) {
        cout << "catch (...)" << endl;
    }
    cout << "finished" << endl;
    return 0;
}

