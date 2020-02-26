/*
 * @Author: haha_giraffe
 * @Date: 2020-02-20 11:22:22
 * @Description: 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
 */
/* 
    解题思路：双指针，首尾双指针和快慢指针都可以
*/
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int f = 0, s = 0;
        int n = nums.size();
        while(f < n){
            while(f < n && nums[f] % 2 == 0){
                f++;
            }
            while(s < f && nums[s] % 2 == 1){
                s++;
            }
            if(f < n) swap(nums[f], nums[s]);
            f++;
            s++;
        }
        return nums;
    }
};