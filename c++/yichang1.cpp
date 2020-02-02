#include <iostream>
using namespace std;
int main(){
    //异常用引用来捕捉，由于异常的机制，他不会直接析构，所以可以用引用
/*    double m, n;
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
*/
            try{
                if (1 == 1) {
                    throw string("dsada");
                }
                else
                {
                    printf("dsadsadasdas\n");
                }
            }
            catch(string &tp){
                cerr << tp;
            }

    return 0;
}

