/*
 * @Author: haha_giraffe
 * @Date: 2020-08-05 11:09:38
 * @Description: 
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
 */
const int MOD = 1e9+7;
class Solution {
public:
    int numWays(int n) {
        if(n == 0 || n == 1){
            return 1;
        }
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        }
        return dp[n] % MOD;
    }
};