#include <bits/stdc++.h>
using namespace std;


//单例模式同时体现打印次数
class Printer
{

public:
    static Printer *getInstance(){
        return printer;
    }
    void printtext(string text)
    {
        cout<< "打印的内容："<<text<<endl;
        m_count++;
    }
    int m_count;

private:
    Printer()
    {
        m_count = 0;
    }
    Printer(const Printer & p)
    {

    }

    static Printer * printer;
};
Printer * Printer::printer = new Printer;

void test01()
{
     Printer * p1 = Printer::getInstance();

     p1->printtext("hhhhhhhhhhhh");
     cout<<p1->m_count<<endl;
}
int main(){

    test01();
    return 0;
}

