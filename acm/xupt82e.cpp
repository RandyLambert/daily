#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
const int max_size = 200000+1000;
char buf[max_size];

int main()
{
    map<char,int> mp;
    mp['x'] = 0;
    mp['t'] = 0;
    mp['C'] = 0;
    mp['p'] = 0;
    mp['c'] = 0;

    int b,ans = 0;
    bool flag=false;
    cin>>b;
    cin>>buf;
    for(int i = 0;i < b;i++){
        if(buf[i] == 'x'){
            mp['x']++; 
        }
        else if (buf[i] == 't'){
            mp[buf[i]] = min(mp['x'],mp[buf[i]]+1); 
        }
        else if(buf[i] == 'C'){
            mp[buf[i]] = min(mp['x'],mp[buf[i]]+1); 

        }
        else if(buf[i] =='p'){
            mp[buf[i]] = min(mp['x'],mp[buf[i]]+1); 
        }
        else if(buf[i] =='c'){
            mp[buf[i]] = min(mp['x'],mp[buf[i]]+1);

            /*flag = true;
            for(auto &key : mp){
                if(key.second == 0){
                    flag = false;
                    break;
                }
            }

            if(flag == true){
                ans++;
                for(auto &key : mp){
                    key.second--;  
                }
            }*/
        }
    }

    cout<<mp['c']<<endl;
    return 0;
}
