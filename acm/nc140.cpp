// nc 140 快排
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    void quicksort(int l,int r,vector<int>& arr){
        if(l > r){
            return ;
        }
        int flag = arr[l];
        int left = l;
        int right = r;
        while(left < right){
            while(arr[right] >= flag && left < right){
                right--;
            }
            while(arr[left] <= flag && left < right){
                left++;
            }
            swap(arr[left],arr[right]);
        }
//         cout<<left<<endl;
        arr[l] = arr[left];
        arr[left] = flag;
//         for(auto &x : arr){
//             cout<<"test "<<x <<" ";
//         }
//         cout<<endl;
        quicksort(l,left - 1,arr);
        quicksort(left + 1,r,arr);
        return ;
    }
    
    vector<int> MySort(vector<int>& arr) {
        // write code here
        quicksort(0, arr.size()-1, arr);
        return arr;
    }
};
