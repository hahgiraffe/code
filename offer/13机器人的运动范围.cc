/*
 * @Author: haha_giraffe
 * @Date: 2020-02-17 20:29:05
 * @Description: 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
 * 一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
 * 例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
 */

/* 
    解题思路：普通的dfs，用一个二维数组表示来表示是否到过
*/
class Solution {
public:
    int get(int num){
        int tmp = 0;
        while(num){
            tmp += num % 10;
            num = num / 10;
        }
        return tmp;
    }
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, 1, -1, 0};
    void dfs(int i, int j, int& num, int k, int m, int n, vector<vector<char>>& gone){
        if(i < 0 || i >= m || j < 0 || j >= n || gone[i][j] == '.' || get(i) + get(j) > k){
            return;
        }
        gone[i][j] = '.';
        num++;
        for(int tmp = 0; tmp < 4; ++tmp){
            int ni = i + dx[tmp];
            int nj = j + dy[tmp];
            dfs(ni, nj, num, k, m, n, gone);
        }
    }
    int movingCount(int m, int n, int k) {
        vector<vector<char>> matrix(m, vector<char>(n, '0'));
        int res = 1;
        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                // if(get(i) + get(j) <= k &&){
                    int num = 0;
                    dfs(i, j, num, k, m, n, matrix);
                    res = max(res, num);
                // }
            }
        }
        return res;
    }
};