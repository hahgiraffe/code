/*
 * @Author: haha_giraffe
 * @Date: 2019-12-02 22:46:55
 * @Description: 最大子序和
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 */

/* 
    解题思路：最简单的dp，dp[i] = max(dp[i-1]+num[i], num[i]);
            进一步优化dp，把空间复杂度O(n) -> O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        // vector<int> dp(n,0);
        int res = nums[0];
        //dp[0]=nums[0];
        int pass_val = nums[0];
        for(int i=1;i<n;++i){
            int new_val  = max(pass_val+nums[i], nums[i]);
            res = max(res,new_val);
            pass_val = new_val;
            // dp[i]=max(dp[i-1]+nums[i],nums[i]);
            // res = max(res,dp[i]);
        }
        return res;
    }
};