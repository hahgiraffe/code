/*
 * @Author: haha_giraffe
 * @Date: 2020-03-17 19:49:38
 * @Description: 给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。
 */
/* 
    解题思路:dp[i][j]表示字符串s[i]到s[j]之间的最长回文子序列长度,
            如果s[i] == s[j] 则dp[i][j] = dp[i+1][j-1] + 2;
            否则dp[i][j] = max(dp[i+1][j], dp[i][j-1])
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i){
            dp[i][i] = 1;
        }
        for(int i = 0; i < n-1; ++i){
            if(s[i] == s[i+1])
                dp[i][i+1] = 2;
            else 
                dp[i][i+1] = 1;
        }
        for(int len = 2; len < n; ++len){
            for(int i = 0; i + len < n; ++i){
                int j = i + len;
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};