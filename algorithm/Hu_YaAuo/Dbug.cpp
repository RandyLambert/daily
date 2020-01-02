#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;
unordered_map<unsigned char,int>mp; 
enum{MAX_LEN = 1024};

int getBit(ifstream &ifile)
{
	static int i = 0;//用来计数返回了几位了
	static unsigned char ch;//接受读取到的信息
	unsigned char bit[8] = {128,64,32,16,8,4,2,1};
	i++;
	if(i == 8)
	{
		ch = ifile.get();
		i = 0;
	}
	return ch&bit[i];
}

int main(){
    ifstream ifile;
    ofstream ofile;
    cout<<"请输入文件名：";
    /* cin>>; */
    ifile.open("./ya.txt");
    if(!ifile){
        cout<<"fail open"<<endl;
        exit(0);
    }

    char tp;
    while(true){
        ifile.read(&tp,1);
        if(ifile.peek() == EOF){
            break;        
        }
        mp[tp]+=1;
    }


    /* int i=0,j,k; */
     /* a[i]='\0'; */
     /* cout<<a<<endl; */

    ifile.close();    
    ofile.close();
    return 0;
}

