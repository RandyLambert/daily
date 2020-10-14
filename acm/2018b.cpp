#include <algorithm>
#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;

char mp[2] = {'0','1'};
string getTwo(int a){
    
    string ans;
    while(a){
        ans += mp[a%2];
        a/=2;
    }
    while(1){
        if(ans.size()==8){
            break;
        }

        if(ans.size() < 8){
            ans+='0';
        }
    }
    reverse(begin(ans),end(ans));
    return ans;
}
int main()
{
    freopen("2018b.txt","r",stdin);
    int cnt = 0;
    //cout<<getTwo(-10)<<endl;
   for(int i = 0;i < 10;i++){
       for(int j = 0;j < 32;j++){
           int num; 
            cin>>num;
          //  cout<<num;
           bitset<8> xx(num);
           string x = xx.to_string();
          // cout<<x;
            //string x = getTwo(num);
           for(int k = 0;k < x.size();k++){
                if(x[k] == '0'){
                    cout<<" ";
                }
                else if(x[k] == '1'){
                    cout<<"*";
                }
           }
           if(cnt < 1){
               cnt++;
           }
           else{
                cnt=0;
                cout<<endl;
           }
       }
   } 
   return 0;
}
