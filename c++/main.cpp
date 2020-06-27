#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    
    /* blank.display(cout); */
//    char ch=myScreen.get();
//    ch=myScreen.get(0,0);
//    myScreen.move(4,0).set('#');

    vector<Person>v;

    creatPerson(v);
    setScore(v);
    showScore(v);
    return 0;
}
