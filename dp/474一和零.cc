/*
 * @Author: haha_giraffe
 * @Date: 2020-02-06 11:01:45
 * @Description: 一和零
 * 在计算机界中，我们总是追求用有限的资源获取最大的收益。
现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。
你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。
 */

/* 
    解题思路：这个其实也是背包问题，只是从一维限制变成二维限制（限制就是0和1的个数，在这个数之内要求满足最大的字符数）
*/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int arrsize = strs.size();
        for(int i = 0; i < arrsize ; ++i){
            string tmpstr = strs[i];
            int z = 0, o = 0;
            for(int j = 0; j < tmpstr.size(); ++j){
                if(strs[i][j] == '1'){
                    o++;
                }
                else{
                    z++;
                }
            }
            // 注意这样是不行的，例如在第一个字符串的循环中，有可能出现dp[j][k] > 1的情况，也就是重复加了两次
            // for(int j = 0; j <= m; ++j){
            //     for(int k = 0; k <= n; ++k){
            //         if(j >= z && k >= o){
            //             dp[j][k] = max(dp[j - z][k - o] + 1, dp[j][k]);
            //         }
            //     }
            // }
            for(int j = m; j >= z; --j){
                for(int k = n; k >= o; --k){
                    dp[j][k] = max(dp[j - z][k - o] + 1 , dp[j][k]);
                }
            }
        }
        return dp[m][n];
        
    }
};