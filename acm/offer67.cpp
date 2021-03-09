class Solution {
public:
    int strToInt(string s) {
        if(s.size() == 0){
            return 0;
        }
        int i = 0;
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
            i++;
        } else if(s[i] == '+'){
            f = true;
            i++;
        } else if(s[i] <= '9' && s[i] >= '0'){
            f = true;
        }
        
        if(s[i] < '0' || s[i] > '9'){
            return 0;
        }

        int sSize = s.size();
        bool flag = false;
        while(i < sSize){
            if(flag == false){
                if(s[i]  < '0' || s[i] > '9'){
                    i++;
                    continue; 
                }
            } else {
                if(s[i]  < '0' || s[i] > '9'){
                    if(f == true){
                        return ans;
                    } else {
                        return -ans;
                    }
                }
            } 

            // cout<<s[i]<<endl;
            int res = s[i] - '0';
            flag = true;
            int c = INT_MAX%10;  
            if(f == true) {      
                if(ans > INT_MAX/10 || (ans == INT_MAX/10 && res >= c)) {
                    return INT_MAX;
                }	
            } else {       
                if(ans > INT_MAX/10 || (ans == INT_MAX/10 && res >= c + 1)) {
                    return INT_MIN;
                }	
            }
            // cout<<ans<<endl;
            ans = ans * 10 + res;
            i++; 
        }
        if(f == true){
            return ans;
        } else {
            return -ans;
        }
    }
};
