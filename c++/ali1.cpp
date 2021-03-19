#include <iostream>
#include <string>
using namespace std;
int atoi(string s){
    if(s.size() == 0){
        return 0;
    }
    int i = 0;
    int maxNum = 2^31-1;
    int minNum = -2^31;
    int ans = 0;
    bool f = false;
    while(s[i] == ' '){
        i++;
    }
    if(s.size() == i){ // 说明全部都是空格
        return 0; 
    }
    if(s[i] == '-'){
        f = false;
    } else if(s[i] == '+'){
        f = true;
    } else if(s[i] <= '9' && s[i] >= '0'){
        f = true;
    }
    else if(s[i] < '0' || s[i] > '9'){
        return 0;
    }
    int sSize = s.size();
    while(i < sSize){
        if(s[i]  < '0' || s[i] > '9'){
            i++;
            continue; 
        }
        int res = s[i] - '0';
        int c = res%10;  
        if(f == true) {      
            if(ans > maxNum/10 && res >= c) {
                return maxNum;
            }	
        } else {       
            if(ans > maxNum/10 && res >= c + 1) {
                return minNum;
            }	
        }
        ans = ans * 10 + res;
        i++; 
    }
    if(f == true){
        return ans;
    } else {
        return -ans;
    }
}