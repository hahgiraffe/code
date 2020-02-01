/*
 * @Author: haha_giraffe
 * @Date: 2020-01-30 10:33:58
 * @Description: 完全平方数
    给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 */
/* 
    解题思路：题目是求最少个数，基本上可以确定使用dp做，一开始想到先把完全平方数取出来，再每个遍历，后面可以直接两层循环
    状态是通过完全平方数进行转移，最后只需要注意边界情况即可
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j * j <= i; ++j){
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }   
        }
        return dp[n];
    }
};