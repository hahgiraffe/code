/*
 * @Author: haha_giraffe
 * @Date: 2020-02-06 10:20:35
 * @Description: 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 */
/* 
    解题思路：这题目想到dp的状态方程不容易，dp[i][j]表示以matrix[i][j]为右下角的矩阵中最大全1正方形边长。
            状态转移方程 dp[i][j] = min( min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int res = 0;
        for(int i=0;i<n;++i){
            if(matrix[i][0]=='1'){
                dp[i][0]=1;
                res = 1;
            }
        }
        for(int j=0;j<m;++j){
            if(matrix[0][j]=='1'){
                dp[0][j]=1;
                res = 1;
            }
        }
        for(int i=1;i<n;++i){
            for(int j=1;j<m;++j){
                if(matrix[i][j]=='1'){
                    dp[i][j]=min(min(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j])+1;
                    res = max(res,dp[i][j]);
                }
            }
        }
        return res*res;
    }
};