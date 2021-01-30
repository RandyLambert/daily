//nc 105
class Solution {
public:
    /**
     * 二分查找
     * @param n int整型 数组长度
     * @param v int整型 查找值
     * @param a int整型vector 有序数组
     * @return int整型
     */
    int upper_bound_(int n, int v, vector<int>& a) {
        // write code here
        int l = 0;
        int r = n-1;
        while(l < r){
            int mid = (l+r)/2;
            if(a[mid] < v){
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if(a[l] >= v){
            return r+1;
        } else {
            return n+1;
        }
        
    }
};
