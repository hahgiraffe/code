/*
 * @Author: haha_giraffe
 * @Date: 2020-03-05 13:00:04
 * @Description: 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。
 */
/* 
    解题思路：因为是递增数组，所以可以用双指针
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() -1;
        int n = nums.size();
        while(l < r){
            if(nums[l] + nums[r] > target){
                r--;
            } else if (nums[l] + nums[r] < target){
                l++;
            } else{
                return {nums[l], nums[r]};
            }
        }
        return {};
    }
};