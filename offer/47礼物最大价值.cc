/*
 * @Author: haha_giraffe
 * @Date: 2020-02-29 20:59:11
 * @Description: 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
 * 你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

 */
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()){
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; ++i){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int j = 1; j < m; ++j){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        for(int i = 1; i < n; ++i){
            for(int j = 1; j < m; ++j){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};