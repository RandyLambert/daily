#include <iostream>
#include <map>
using namespace std;
template <typename T1,typename T2>
auto add(T1 x,T2 y)->decltype(x+y);//1,声明一种函数返回类型，特殊用法

int getSize();
/* typedef typename decltype(obj)::iterator iType; *///2.函数模板的应用，获取obj的类型，里面的typename可以不要，那个是给编译器看的

auto cmp= [](const int a,int b){
    return a<b;
};

map<int,decltype(cmp)> q;//lambdas一般很难写出是什么类型的，所以使用auto和decltype来辅助编程
int main(){
    map<int,double> a;
    decltype(a)::value_type c; //判断类型
    int tempAi = 2;

    /*1.dclTempA为int.*/
    decltype(tempAi) dclTempAi;
    /*2.dclTempB为int，对于getSize根本没有定义，但是程序依旧正常，因为decltype只做分析，并不调用getSize().*/
    decltype(getSize()) dclTempBi;
    
    double tempA = 3.0;
    const double ctempA = 5.0;
    const double ctempB = 6.0;
    const double *const cptrTempA = &ctempA;
    
    /*1.dclTempA推断为const double（保留顶层const，此处与auto不同）*/
    decltype(ctempA) dclTempA = 4.1;
    /*2.dclTempA为const double，不能对其赋值，编译不过*/
    /* dclTempA = 5; */
    /*3.dclTempB推断为const double * const*/
    decltype(cptrTempA) dclTempB = &ctempA;
    /*4.输出为4（32位计算机）和5*/
    cout<<sizeof(dclTempB)<<"    "<<*dclTempB<<endl;
    /*5.保留顶层const，不能修改指针指向的对象，编译不过*/
    /* dclTempB = &ctempB; */
    /*6.保留底层const，不能修改指针指向的对象的值，编译不过*/
    /* *dclTempB = 7.0; */

    int tempAy = 0, &refTempAy = tempAy;
    /*1.dclTempA为引用，绑定到tempA*/
    decltype(refTempAy) dclTempAy = tempAy;
    /*2.dclTempB为引用，必须绑定到变量，编译不过*/
    /* decltype(refTempAy) dclTempBy = 0; */
    /*3.dclTempC为引用，必须初始化，编译不过*/
    /* decltype(refTempAy) dclTempCy; */
    /*4.双层括号表示引用，dclTempD为引用，绑定到tempA*/
    decltype((tempA)) dclTempD = tempA;

    const int ctempAy = 1, &crefTempA = ctempA;

    /*5.dclTempE为常量引用，可以绑定到普通变量tempA*/
    decltype(crefTempA) dclTempE = tempA;
    /*6.dclTempF为常量引用，可以绑定到常量ctempA*/
    decltype(crefTempA) dclTempF = ctempA;
    /*7.dclTempG为常量引用，绑定到一个临时变量*/
    decltype(crefTempA) dclTempG = 0;
    /*8.dclTempH为常量引用，必须初始化，编译不过*/
    /* decltype(crefTempA) dclTempH; */
    /*9.双层括号表示引用,dclTempI为常量引用，可以绑定到普通变量tempA*/
    decltype((ctempA))  dclTempI = ctempA;
    
    return 0;
}
