class Solution {
public:
    int MOD = 1000000007;
    int fn[101] = {0};
    int fib(int n) {
        if(n == 0){
            return 0;
        } else if(n == 1 || n == 2){
            return  1;
        } else {
            if(fn[n-2] == 0)
                fn[n-2] = fib(n-2)%MOD;
            if(fn[n-1] == 0)
                fn[n-1] = fib(n-1)%MOD;
            return (fn[n-2]+fn[n-1])%MOD; 
        }
    }
};
