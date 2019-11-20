#include <bits/stdc++.h>
using namespace std;
int c,d;
const int e=10,f=10;
static int i;
//函数调用永远不要返回局部变量
//局部变量在栈区返回之后就没了，自动释放
//
/* int* fun(int b){ //形参也会被放到栈区 */
/*     int a = 10; */
/*     return &a; */
/* } */
//利用new可以创建
void fun(int **p){
    *p = new int(10);
    cout<<"p地址"<<p<<endl;
    /* *p = 100; */
    /* return p; */
}
int main(){

    int a,b;
    /* int *aa = &a; */
    /* cout<<&aa<<endl; */
    static int j;
    const int g = 10,h = 10;
    char x[100] = "ffassdda";
    const char *xx = "dadsdasda";
    //有局部修饰的，局部变量和const修饰的局部变量，在栈区
    cout<<"局部变量"<<&a<<" "<<&b<<endl;
    cout<<"const修饰的局部变量"<<&g<<" "<<&h<<endl;
    cout<<"普通局部变量字符串"<<&x<<endl;
    putchar('\n');
    putchar('\n');
    //在全局区的，劝酒变量，静态变量，常量：字符串常量和const修饰的全局变量
    cout<<"静态局部变量和静态全局变量"<<&i<<" "<<&j<<endl;
    cout<<"全局变量"<<&c<<" "<<&d<<endl;
    cout<<"const修饰的全局变量"<<&e<<" "<<&f<<endl;
    cout<<"字符常量"<<&("hello word");
    printf(" %p\n",xx);

    int *p = NULL;
    fun(&p);
    cout<<*p<<endl;
    /* cout<<*p<<endl; //第一次可以正确返回数字是因为编译器做了保留 */
    /* cout<<*p<<endl; //返回局部变量的地址 */

    return 0;
}
