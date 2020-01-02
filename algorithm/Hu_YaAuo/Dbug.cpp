#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;
unordered_map<unsigned char,int>mp; 
enum{MAX_LEN = 1024};
int main(){
    ifstream ifile;
    ofstream ofile;
    cout<<"请输入文件名：";
    /* cin>>; */
    ifile.open("./ya.txt");

    /* int i=0,j,k; */
    char buf[MAX_LEN];
    string x;
     while(true){      //读标题,请对比cin.get(),不可用>>,它不能读白字符
        /* if(a[i]=='\n') break; */
         if(ifile.eof()){
             break;
         }
         ifile>>x;
     }
         cout<<x;
     /* a[i]='\0'; */
     /* cout<<a<<endl; */

    ifile.close();    
    ofile.close();
    return 0;
}

