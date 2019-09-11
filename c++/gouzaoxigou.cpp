#include <iostream>
#include <string>

using namespace std;
class Animal
{
public:
    Animal(const string theName): name(theName){ cout<<"anim jilei"<<endl; };
    ~Animal()
    {
        cout<<"hhhhhhhhhhhhh"<<endl;
    }
    void eat()
    {
        cout<<name<<"dasdasdasdas"<<endl;
    }
protected:
    string name;

};

class Pig:public Animal
{
public:
    Pig(const string theName);
    ~Pig(){delete[] yy; cout<<"linuxsky died"<<endl;};
    void print();
    void print(int fuck,int fuck2);
    static void count(){
        static int num;
        num++;
        cout<<num<<endl;
    }

    Pig hhh(Pig x){
        x.hh = x.hh*this->hh;
        return x;
    }
    char fuck;
    int hh;
    Pig operator *(Pig fuck2){
        Pig c("xilei");

        c.hh = fuck2.hh + this->hh;    
        return c;
    }
    
private:
    int *yy = new int[10];
protected:
    int fuck2;
};

void Pig::print()
{
    cout<<hh<<"   "<<*yy<<"    "<<*(yy+1)<<endl;
}

/* void Pig::count(){ */
/*     num++; */
/*     cout<<num<<endl; */
/* } */

Pig::Pig(const string theName):Animal(theName),hh(10)
{
    *yy = 2;
    *(yy+1) = 34;
    *(yy+2) = 4;
}

void Pig::print(int fuck,int fuck2)
{
    cout<<fuck*fuck2<<endl;
}

/* Pig::~pig(){} */
int main(){
    const char *xx = "pii\0";
    /* cin>>xx; */
    Pig pig(xx);
    pig.eat();
    pig.print();
    pig.fuck = '@';
    /* pig.fuck2 = 1; */
    cout<<pig.fuck<<endl;
    pig.print(1000,1000);

    Pig two{"das"};
    two.hh = 10;
    
    Pig xxx = two*pig;
    cout<<xxx.hh<<endl;

    two.count();
    two.count();
    two.count();
    two.count();
    two.count();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    pig.count();

    return 0;
}
