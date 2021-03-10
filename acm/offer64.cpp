class Solution {
public:
    int sumNums(int n) {
        if(n != 0){
            return n + sumNums(n-1);
        } else {
            return 0;
        }
    }
};
