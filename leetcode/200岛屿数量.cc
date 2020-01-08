/*
 * @Author: haha_giraffe
 * @Date: 2020-01-04 20:52:18
 * @Description: 岛屿数量
 * 给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围,
 * 并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
 */

/* 
    解题思路：注意边界条件，一开始递归条件就要直接写好return这样比较不容易出错，每次进入递归就把所有的都走遍即可。
*/

class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void dfs(vector<vector<char>>& grid, vector<vector<char>>& gone, int i, int j){
        if(i<0 || i >= grid.size() || j <0 || j >=grid[0].size() || gone[i][j] == '1' || grid[i][j] == '0'){
            return;
        }
        gone[i][j] = '1';
        for(int k=0; k<4; ++k){
            int tmpi = i + dx[k];
            int tmpj = j + dy[k];
            dfs(grid, gone, tmpi, tmpj);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0){
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<char>> gone(vector<vector<char>>(n, vector<char>(m, '0')));
        int res = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == '1' && gone[i][j] == '0'){
                    dfs(grid, gone, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};