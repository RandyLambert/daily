#include <iostream>
#include <vector>
#include <type_traits>
/* template <typename T> */
/* using Vec = std::vector<T,MyAlloc<T>>;//不能用define和typedef去用 */ 
//缺点：不可能进行 模板特化，化名还是不能代表本尊

/* Vec<int> coll;//等于 */
/* std::vector<int,MyAlloc<int>> coll; */
#define SIZE 1024

template<typename Container>
void test_moveable(Container c)
{//只能传进去容器
    typedef typename __gnu_cxx::iterator_traits<typename Container::iterator>::value_type Valtype;//萃取器
    for(long i = 0;i < SIZE;i++)
        c.insert(c.end(),Valtype());

    optput_static_data(*(c.begin()));//静态数据调用了多少次
    Container c1(c);
    Container c2(std::move(c));
    c1.swap(c2);
    //test
    //test_moveable(list<MyString>())
    //test_moveable(list<MyStrNoMove>())
}


int main(){

    return 0;
}

