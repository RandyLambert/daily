#include <bits/stdc++.h>
using namespace std;
class MyInsect{
public:
    void operator()(const int &x) const {
        cout<<x<<endl;
    }
};
int main(){
    //插入迭代器
    vector<int> vec;
    auto it = back_inserter(vec); //通过他赋值会会将元素添加到vec中，还遵守这决不修改容器的大小
    //（不插入、不删除）。有了插入迭代器，既使得算法库可以通过迭代器对容器插入新的元素，又不违反这一承诺，即保持了设计上的一致性。
    *it = 12312;
    *it = 12341;
    *it = 2;
    fill_n(it,10,312);
    for_each(begin(vec),end(vec),MyInsect());

    list<int> lst = {1,2,3,4,5,6,7,8,9};
    list <int> lst2 = {10},lst3 = {10},lst4 = {10};
    copy(lst.cbegin(),lst.cend(),back_inserter(lst2));//头插
    copy(lst.cbegin(),lst.cend(),inserter(lst3,lst3.begin())); //中间某个位置插
    copy(lst.cbegin(),lst.cend(),front_inserter(lst4));//尾插

    for_each(begin(lst2),end(lst2),MyInsect());
    for_each(begin(lst3),end(lst3),MyInsect());
    for_each(begin(lst4),end(lst4),MyInsect());

    int a[10] = {1,2,3,4,5,6,7,8,9,0};
    unique_ptr<int>b1(new int[10]);
    int b[10];
    auto x= b1.get();

    copy(begin(a),end(a),x);
    copy(begin(a),end(a),b);
    for(int i = 0;i < 10;i++){
        cout << *(x+i) <<"dasdsadas"<<endl;
    }
    for_each(begin(b),end(b),MyInsect());
    return 0;
}
