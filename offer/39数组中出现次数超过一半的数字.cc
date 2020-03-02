/*
 * @Author: haha_giraffe
 * @Date: 2020-02-28 20:12:30
 * @Description: 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 */
/* 
    解题思路：保留一个数字和一个次数，遍历数组，如果相同则次数加一，不相同则次数减一，如果次数为零则重置
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int num = nums[0];
        int times = 1;
        for(int i = 1; i < n; ++i){
            if(nums[i] == num){
                times++;
            } else {
                times--;
                if(times == 0){
                    num = nums[i];
                    times = 1;
                }
            }
        }
        return num;
    }
};