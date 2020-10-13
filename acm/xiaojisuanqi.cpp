#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
typedef unsigned long long ull; 
map<char,ull> charToNum;
map<ull,char> numToChar;
ull toTen(string& num,ull jinzhi){
    ull ans = 0;
    ull len = num.size();
    ull x = 1;
    if(len == 0){
        return 0;
    }
    for(int i = len-1;i >= 0;i--){
        ans = ans + charToNum[num[i]]*x;
         x = x*jinzhi;
    }

    return ans;
}

string toAll(ull tenNum,ull jinzhi){
    string ans;
    while(tenNum){
        ans += numToChar[tenNum%jinzhi];
        tenNum = tenNum/jinzhi;
    }
    reverse(ans.begin(),ans.end());

    return ans;
}


int main()
{
    //freopen("input1.txt","r",stdin);
    //freopen();
    for(int i = '0';i <= '9';i++){
        charToNum[i] = i - '0';
        numToChar[i-'0'] = i;
    }
    for(int i = 'A';i <= 'Z';i++){
        charToNum[i] = i - 'A'+10;
        numToChar[i-'A'+10] = i;
    }

    //string xxx = "100000";
    //cout<<toTen(xxx,2)<<endl;
    //cout<<toAll(1056,8)<<endl;

    
    
    ull cnt = 0;
    ull jinzhi = 10;
    ull flag = 0;
    string op,num;
    ull numm;


    cin>>numm;
    while(numm--) {
        cin>>op;
        if(op == "CLEAR"){
            cnt = 0;
        }
        else if(op == "EQUAL"){
            cout<<toAll(cnt,jinzhi)<<endl;
        }
        else if(op == "NUM"){
            string tempNum;
            cin>>tempNum;
            if(flag == 0){
                cnt = toTen(tempNum,jinzhi);
            }
            else if(flag == 1){
                ull tem = toTen(tempNum,jinzhi);
                cnt += tem;
                flag = 0;
            }
            else if(flag == 2){
                ull tem = toTen(tempNum,jinzhi);
                cnt -= tem;
                flag = 0;
            }
            else if(flag == 3){
                ull tem = toTen(tempNum,jinzhi);
    //            cout<<tem<<" "<<cnt<<" "<<toAll(cnt,jinzhi)<<endl;
                cnt *= tem;
      //          cout<<tem<<" "<<cnt<<" "<<toAll(cnt,jinzhi)<<endl;
                flag = 0;
            }
            else if(flag == 4){
                ull tem = toTen(tempNum,jinzhi);
                //cout<<tem<<" "<<cnt<<" "<<toAll(cnt,jinzhi)<<endl;
                cnt /= tem;
                flag = 0;
                //cout<<tem<<" "<<cnt<<" "<<toAll(cnt,jinzhi)<<endl;
            }
            else if(flag == 5){
                ull tem = toTen(tempNum,jinzhi);
                cnt %= tem;
                flag = 0;
            }
            
        }
        else if(op == "CHANGE"){
            cin>>jinzhi;
        }
        else if(op == "ADD"){
            flag = 1;
        }
        else if(op == "SUB"){
            flag = 2;
        }
        else if(op == "MUL"){
            flag = 3;
        }
        else if(op == "DIV"){
            flag = 4;
        }
        else if(op == "MOD"){
            flag = 5;
        }

    }

    return 0;
}
