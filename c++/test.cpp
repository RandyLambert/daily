#include <bits/stdc++.h>
#include <any>
using namespace std;
class a /*final*/{
public:
    int a1 = 10;
    /* a(){ */
    /*     a1 = 10; */
    /* } */
    a(int x){}
    a()= default;
    virtual void c(){};
};
class b : public/*private*/ a{
/* protected: */
public:
    void hhh() const & {
        cout<<a1<<endl;
    }
    void yyyy(){
        cout<<"da"<<endl;
    }
};

class c{
public:
    /* int a; */
    void aa(){}
    void aaa(){}
};

class SizeComp{
public:
    SizeComp(size_t i):sz(i){  } //形参负责捕获的变量
    //该调用运算符的返回类型，形参和函数体都与lambda一致
    bool operator()(const string&strr)const
    {
        /* cout<<strr.size()<<endl; */
        return strr.size() >= sz;
    }
    void print(){
        cout<<sz<<endl;
    }
private:
    size_t sz;  //该数据成员对应该值捕获的变量
};
int main(){
    //浮点数的存储
    printf("%lf\n",(3.14+1e20)-1e20);
    printf("%lf",3.14+(1e20-1e20));
    std::any z = 42;
    b x;
    x.hhh();
    x.c();
    cout<<x.a1<<endl;
    cout<<sizeof(c)<<endl; //当一个类没有一个数据成员定义的时候，这个类大小为1，有了之后是数据大小
 
    string y = string(10,'x');
    cout<<y<<endl;
    /* const int &xxx = 10; */
    int i = 121;
    ++i = 10; //前置++返回的是一个对象
    /* i++ = 10;//后置++返回的是一个值,所以该行语句错误 */
    cout<<i<<endl;

    vector<string>q;
    q.push_back("sdasdsadsa");
    q.push_back("sdasdsxxxxxxadsa");
    q.push_back("sdasdxxxsadsa");
    q.push_back("sdaxxxsdsadsa");
    q.push_back("sdasdxxxxxxxxxxxsadsa");
    q.push_back("sdasdsadsaaaaaaaa");
    *back_inserter(q) = "dasssssss";
    *back_inserter(q) = "dadasdadasssssss";
    *back_inserter(q) = "dasssssdasss";
    *back_inserter(q) = "dassssssdasdasdsadas";
    SizeComp a(10);
    a.print();
    a("32131");
    auto j = find_if(begin(q),end(q),SizeComp(20));
    auto jj = find_if(begin(q),end(q),a);
    cout<<*jj<<endl;
    size_t sz = 20;
    auto wc = find_if(begin(q),end(q),
                      [sz](const string &a)
                      {return a.size() >= sz;});
    cout<<*wc<<endl;
    int* aia = new int;
    *aia = 10; 
    int bib = std::move(*aia);
    cout<<*aia<<" "<<bib<<endl;
    return 0;
}

/* //hhhhhhhhhhhh */
/* //hhhhhhhhhhhh */
/* //hhhhhhhhhhhh */
/* //hhhhhhhhhhhh */
/* //hhhhhhhhhhhh */
/* //hhhhhhhhhhhh */
/* //hhhhhhhhhhhh */
/* //hhhhhhhhhhhh */
