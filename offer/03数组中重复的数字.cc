/*
 * @Author: haha_giraffe
 * @Date: 2020-02-15 20:06:10
 * @Description: 找出数组中重复的数字。
 * 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
 */

/* 
    解题思路：桶的思想，在数组中连续交换，直到放到正确的位置
*/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            while(nums[i] != i){
                if(nums[i] == nums[nums[i]]){
                    return nums[i];
                }
                else{
                    swap(nums[i], nums[nums[i]]);
                }
            }
        }
        return 0;
    }
};