#include <iostream>
#include <fstream>
using namespace std;
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

    return 0;
}
