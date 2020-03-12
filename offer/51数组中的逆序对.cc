/*
 * @Author: haha_giraffe
 * @Date: 2020-03-09 15:53:48
 * @Description: 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
 */
/* 
    解题思路：就是归并排序，两个比较的时候多加一句
*/
class Solution {
public:
    // int reversePairs(vector<int>& nums) {
    //     int n = nums.size();
    //     int res = 0;
    //     for(int i = 0; i < n; ++i){
    //         for(int j = i+1; j < n; ++j){
    //             if(nums[i] > nums[j]){
    //                 res++;
    //             }
    //         }
    //     }
    //     return res;
    // }
    void mergesort(vector<int>& nums, int l , int r, vector<int>& vec, int& res){
        if(l >= r){
            return;
        }
        int mid = l + (r - l)/2;
        mergesort(nums, l , mid, vec, res);
        mergesort(nums, mid+1, r, vec, res);
        int idx1 = l, idx2 = mid+1, idx3 = l;
        while(idx1 <= mid && idx2 <= r){
            if(nums[idx1] <= nums[idx2]){
                vec[idx3++] = nums[idx1++];
            } else {
                res += mid - idx1 + 1;          //只多加这一句话
                vec[idx3++] = nums[idx2++];
            }
        }
        while(idx1 <= mid){
            vec[idx3++] = nums[idx1++];
        }
        while(idx2 <= r){
            vec[idx3++] = nums[idx2++];
        }
        for(int t = l; t <= r; ++t){
            nums[t] = vec[t];
        }
        return;
    }
    
    int reversePairs(vector<int>& nums){
        int n = nums.size();
        vector<int> vec(n, 0);
        int res = 0;
        mergesort(nums, 0, n-1, vec, res);
        return res;
    }
};