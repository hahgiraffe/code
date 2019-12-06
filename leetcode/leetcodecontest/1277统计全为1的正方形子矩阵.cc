/*
 * @Author: haha_giraffe
 * @Date: 2019-12-02 09:16:01
 * @Description: 统计正方形子矩阵
 * 给你一个 m * n 的矩阵，矩阵中的元素不是 0 就是 1，请你统计并返回其中完全由 1 组成的 正方形 子矩阵的个数。
 */

/* 
    解题思路：二维前缀和，最简单的思路，用一个数组grid统计当前数据的前缀和，然后最后用一个len表示长度进行判断即可。
            这里有一个技巧就是当matrix转移到grid的时候把其放到从[1, n]，这样可以有效在删除格子的时候不用考虑边缘
*/
class Solution {
public:
    int grid[350][350];
    int get(int i, int j, int len){
        int x = i+len-1;
        int y = j+len-1;
        return grid[x][y] - grid[i-1][y] - grid[x][j-1] + grid[i-1][j-1];
    }
    int countSquares(vector<vector<int>>& matrix) {
        //二维前缀和
        memset(grid, 0, sizeof(grid));
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                grid[i+1][j+1]=matrix[i][j];
            }
        }
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                grid[i][j] += grid[i][j-1];
            }
        }
        for(int j=1; j<=m; ++j){
            for(int i=1; i<=n; ++i){
                grid[i][j] += grid[i-1][j];
                // printf("grid : %d",grid[i][j]);
            }
        }

        int res = 0;
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                for(int len = 1; i+len-1 <= n && j+len-1 <= m ;++len){
                    if( get(i,j,len) == len*len){
                        res++;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return res;
    }
};