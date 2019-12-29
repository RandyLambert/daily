#include <iostream>
#include <cstdlib>
using namespace std;
//函数模板机制结论：
//编译器并不把函数模板处理成能够处理的任何类型的函数
//函数模板通过集体类型产生不同的函数（通过函数模板产生模板函数）
//编译器会对函数模板进行了两次编译，在声明的地方对模板代码本身进行编译，在调用的地方对参数替换后的代码进行编译


//模板的局限性，如果代码实现是定义了赋值操作a=b，但是T为数组，或者是没有这种操作数的类型，这种假设就不成立了
//解决方案：提供独特的具体化实现

//利用选择排序，对int和char进行排序
//普通函数能进行自动类型转化，函数模板不可以
//普通函数可以和模板函数进行重载，优先调用普通函数，如果想要去强制走模板，谣传一个空参数列表
//函数模板也可以发生函数重载
//如果函数模板可以产生更好的匹配，那么优先使用函数模板，比如如果要是普通函数要进行自动类型转换，函数模板不需要，那么使用函数模板
/* template<class T> */
/* T mySwap(T &a ,T &b){ */
/*     T temp = a; */
/*     a = b; */
/*     b =  temp; */
/* } */
template<class T>
T mySwap(T &a ,T &b){
    T temp = std::move(a);
    a = std::move(b);
    b =  std::move(temp);
}


template<class T>
void mySort(T *arr,int len){
    for(int i = 0;i < len;i++){
        for(int j = i+1;j < len;j++){
            if(arr[i] > arr[j]){
                mySwap<T>(arr[i],arr[j]);
            }
        }
    }
}

template<class T>
void Print(T *arr,T len){
    for(int i = 0;i<len;i++)
        cout<<arr[i]<<endl;
}
void test01(){

    char arr[] = {1,2,2,3,4,5,7,8,21};
    char arr1[] = {'1','2','3','7','0','a','4','g','r'};
    int len = sizeof(arr1)/sizeof(char);
    mySort<char>(arr1,len);
    Print<char>(arr1,len);

}
int main(){
    test01();

    return 0;
}
