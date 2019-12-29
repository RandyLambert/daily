#include <iostream>
#include <fstream>
using namespace std;
class a{
public:
    int x;
    int y;
    void print(){cout<<x<<y<<endl;}
};


class aa{
private:
    void fuc1();
};
void aa::fuc1(){
    cout<<"dasdasd"<<endl;
}
int main(){
    int i;
while(1)
{
   cin >> i;
   cout << i << endl;
}
    ifstream in("hello.txt");

    while(!in.eof()){
        char ch = in.get();
        cout << ch;
    }
    in.clear();
    in.seekg(0,ios::beg);

    while(!in.eof()){
        char ch = in.get();
        cout << ch;
    }
    a x = {1,2};
    x.print();

    return 0;
}
