// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a = 0;
        do {
            a = (rand7() - 1)*7 + rand7();
        } while(a > 40);
        return a%10+1;
    }
};
