class Solution {
public:
    int hammingWeight(uint32_t n) {
        int x = 0;
        for(int i = 0;i < 32;i++){
            if(n&1 == 1){
                x++;
            }
            n>>=1;
        }
        return x;
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {

    int x = 0;
    while(n!=0){
        n = n&(n-1);
        x++;
    }
    return x;
    }
};
