/*
 * @Author: haha_giraffe
 * @Date: 2020-02-07 11:23:26
 * @Description: 这里有 d 个一样的骰子，每个骰子上都有 f 个面，分别标号为 1, 2, ..., f。
我们约定：掷骰子的得到总点数为各骰子面朝上的数字的总和。
如果需要掷出的总点数为 target，请你计算出有多少种不同的组合情况（所有的组合情况总共有 f^d 种），模 10^9 + 7 后返回。

 */

/* 
    解题思路：这题很经典的DP问题，dp[i][j]表示投掷i次色子得到总点数j的次数。
            状态转移dp[i][j] = dp[i-1][1] + dp[i-1][2] + ... + dp[i-1][f] (k为遍历条件)
*/
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        const int MOD = 1e9+7;
        vector<vector<int>> dp(31, vector<int>(1001, 0));
        for(int i = 1 ; i <= f && i <= target; ++i){
            dp[1][i] = 1;
        }
        int targetmax = f * d;
        for(int i = 2; i <= d; ++i){
            for(int j = i; j <= targetmax; ++j){
               for(int k = 1; j - k >= 0 && k <= f; ++k){
                   dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
               }
            }
        }
        return dp[d][target];
    }
};