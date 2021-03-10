class Solution {
public:
    string replaceSpace(string s) {
        if(s.size() == 0){
            return s;
        }
        int count = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == ' '){
                count++;
            }
        }
        int oldSize = s.size();
        s.resize(oldSize + count*2);
        
        for(int i = s.size()-1,j = oldSize - 1;i > j;i--,j--){
            if(s[j] != ' '){
                s[i] = s[j];
            } else {
                s[i]   = '0';
                s[i-1] = '2';
                s[i-2] = '%';
                i-=2;
            }
        }
        return s;
    }
};
