/*
 * @Author: haha_giraffe
 * @Date: 2020-02-07 12:05:29
 * @Description: 目标和
 * 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
    返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
 */

/* 
    解题思路：这题目很经典。dp[i][j]表示前i个数和为j的方法数。这道题目有一个注意的点，就是dp中负数的处理。本题所有都+1000，相应的一开始初始化数组的时候也要+1000
            一开始想到的状态方程是dp[i][j] = dp[i - 1][j - nums[i]] + dp[i - 1][j + nums[i]]。其实和下面的是一样的
            状态转移方程：dp[i][j + nums[i]] += dp[i-1][j] && dp[i][j - nums[i]] += dp[i-1][j]
    这种类型的题目还需要多练习，其实是01背包的变形
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<vector<int>> dp(25, vector<int>(2050, 0));
        int n = nums.size();
        dp[0][nums[0] + 1000] = 1;
        dp[0][-nums[0] + 1000] += 1;
        for(int i = 1; i < n; ++i){
            for(int j = -1000; j <= 1000; ++j){
                if(dp[i-1][j + 1000] > 0){
                    dp[i][j + nums[i] + 1000] += dp[i - 1][j + 1000];
                    dp[i][j - nums[i] + 1000] += dp[i - 1][j + 1000];
                }
            }
        }
        return S > 1000 ? 0 : dp[n-1][S + 1000];
    }
};