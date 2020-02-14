/*
 * @Author: haha_giraffe
 * @Date: 2020-02-08 11:28:07
 * @Description: 分割等和子集
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
注意:
每个数组中的元素不会超过 100
数组的大小不会超过 200
 */
/* 
    解题思路：背包问题，dp[i][j]表示前i个元素和为j的有无
            记dp[i][j]为在区间[0,i]中,nums是否存在若干个数字，使得他们的和为j
            那么对dp[i][j]
            若nums[i] == j,即只放入nums[i]即能满足,故dp[i][j] = true;
            若nums[i] > j,即nums[i]必然不能放入集合中,dp[i][j] = dp[i-1][j],
            若nums[j] < j,那么nums[i]有可能可以放入集合中,
            若dp[i-1][j-nums[i]]为true，那么必然能放入，dp[i][j]为true,
            若dp[i-1][j]为true,那么不需要放入nums[i]，dp[i][j]为true,
            综上取dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]

*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int target = sum / 2 ;
        vector<vector<bool>> dp(n+1, vector<bool> (target+1, false));
        if(nums[0] <= target){
            dp[0][nums[0]] = true;
        }
        for(int i = 1; i < n; ++i){
            for(int j = 0; j <= target; ++j){
                if(nums[i] == j){
                    dp[i][j] = true;
                    continue;
                }
                dp[i][j] = dp[i-1][j];
                if(j >= nums[i]){
                    dp[i][j] = dp[i][j] | dp[i-1][j - nums[i]];
                }
            }
        }
        return dp[n-1][target];
    }
};