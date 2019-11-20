#include <bits/stdc++.h>
using namespace std;
int main(){

    string a1;
    stringstream st;

    while(getline(cin,a1))
    {
        //clear()，这个名字让很多人想当然地认为它会清除流的内容。
        //实际上，它并不清空任何内容，它只是重置了流的状态标志而已！
        /* st.clear(); */

        /* 原型： void clear (iostate state = goodbit); */
        /* 标志位一共有4种， goodbit, eofbit, failbit, badbit */
        /* clear可以清除掉所有的error state */

        // 去掉下面这行注释，清空stringstream的缓冲，每次循环内存消耗将不再增加!
        //st.str("");
        //
        if(a1.size()==0){
            break;
        }
        string x;
        /* char xxx[12] = "dasdsa"; */
        istringstream st1(x);//istringstream只能从string读取数据
        st1.str(a1);
        ostringstream st2;
        st2<<a1;
        /* st<<a1; */
        st1>>a1;
        if(!st2.str().empty()){
            cout<<"     "<<st2.str()<<endl;
        }
    }

    return 0;
}
