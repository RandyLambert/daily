#include <iostream>
using namespace std;
class Printer
{
public:
    static Printer * getInstance(){
        return printer;
    }
private:
    Printer()
    {

    }
    Printer(const Printer & p){

    }
    static Printer * printer;
};

Printer * Printer::printer = new Printer;
int main(){

    return 0;
}
