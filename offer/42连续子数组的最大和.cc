/*
 * @Author: haha_giraffe
 * @Date: 2020-02-28 22:54:51
 * @Description: 输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
 * 要求时间复杂度为O(n)。
 */
/* 
    dp
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        int res = dp[0];
        for(int i = 1 ; i < n; ++i){
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};