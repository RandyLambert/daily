#include <iostream>
using namespace std;

//子类必须重写父类的纯虚函数，不然两个函数都是不可生成对象的，那么这两个类也就没有意义 
//
//虚析构
//解决问题是 当子类空间中有堆区内容，释放的时候导致释放的不干净，内存泄露
//virtual ~Animal(){
//cout <<"Animal的析构函数调用"<<endl;
//}
//写了以后，删除父类时，先去找子类的析构函数，运行之后在调用父类的析构函数 
//
//纯虚析构
//有声明 也必须有实现，类外实现
//如果一个类中 有了纯虚析构函数，那么这个类也属于抽象类
//
//作用： 在虚析构函数的基础上使得基类成为抽象类。所以主要有如下两个作用：
/* 删除对象时，所有子类都能进行动态识别 */
/* 使得基类成为抽象类 */
/* 注意： */

/* 由于最终会调用到基类的析构函数，所以即使基类的析构函数为纯虚的也要给出析构函数的实现，否则产生链接错误 。 */
/* 当基类的析构函数为纯虚析构函数时，派生类既是不实现析构函数也是可以实例化的，这是因为编译器会为其提供默认的析构函数。 */

//抽象层
//抽象的cpu
class CPU
{
public:
    virtual void calculate() = 0;

};

//抽象的显卡
class Videocard{
public:
    virtual void videocard() = 0;
};

//抽象的内存
class Memory
{
public:
    virtual void storge() = 0;
};

//电脑类
class computer
{
public:
    CPU * cpu;
    Videocard *card;
    Memory *mem;
    computer(CPU * cpu,Videocard *card,Memory *mem){
        this->cpu = cpu;
        this->card = card;
        this->mem = mem;
    }

    void dowork(){
        this->cpu->calculate();
        this->card->videocard();
        this->mem->storge();
    }

    ~computer(){
        if(cpu!=nullptr){
            delete cpu;
            cpu = nullptr;
        }

        if(card!=nullptr){
            delete card;
            card = nullptr;
        }

        if(mem!=nullptr){
            delete mem;
            mem = nullptr;
        }
    }
};


//上面全是抽象，下面是实现



class intelCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout << "intel的cpu开始计算"<<endl;
    }
};

class interMemory : public Memory
{
public:
    virtual void storge(){
        cout<<"intel的内存条开始存储了"<<endl;
    }  
};


class intelVideocard : public Videocard
{
public:
    virtual void videocard(){
        cout<<"intel的videocard开始使用了"<<endl;
    }
};


class legionCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout << "legion的cpu开始计算"<<endl;
    }
};

class legionMemory : public Memory
{
public:
    virtual void storge(){
        cout<<"legion的内存条开始存储了"<<endl;
    }  
};


class legionVideocard : public Videocard
{
public:
    virtual void videocard(){
        cout<<"legion的videocard开始使用了"<<endl;
    }
};

void test01()
{
    //第一台电脑组装
    CPU *cpu = new intelCPU;
    Memory * memory = new interMemory;
    Videocard * videocard = new intelVideocard;
    computer myComputer(cpu,videocard,memory);
    myComputer.card->videocard();
    myComputer.cpu->calculate();
    myComputer.mem->storge();

    cout<<"--------------------------------"<<endl;
    //第二台电脑组装
    CPU *cpu2 = new legionCPU;
    Memory * memory2 = new legionMemory;
    Videocard * videocard2 = new legionVideocard;
    computer *myComputer2 = new computer(cpu2,videocard2,memory2);
    myComputer2->dowork();
    delete myComputer2;

    cout<<"--------------------------------"<<endl;
    //第二台电脑组装
    CPU *cpu3 = new legionCPU;
    Memory * memory3 = new interMemory;
    Videocard * videocard3 = new legionVideocard;
    computer *myComputer3 = new computer(cpu3,videocard3,memory3);
    myComputer3->dowork();
    delete myComputer3;
}
int main(){
    test01();
    return 0;
}
