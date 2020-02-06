#include <iostream>
template<typename T,template<class> class Container>
#define SIZE 1000
class XCIs
{
private:
    Container<T> c;
public:
    XCIs(){//构造函数
        for(long i = 0;i<SIZE;i++){
            c.insert(c.end(),T());
        }
    }

    output_static_data(T());
    Container<T>c1(c);
    Container<T>c1(std::move(c));
    c1.swap(c2);

};
int main(){

    return 0;
}

