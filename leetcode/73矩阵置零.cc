/*
 * @Author: haha_giraffe
 * @Date: 2019-12-05 22:32:23
 * @Description: 矩阵置零
 * 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
 */

/* 
    解题思路：最简单的一种方法就是用m*n的一个新矩阵表示，如果原矩阵中出现0直接在新矩阵中置零即可，时间复杂度O(n^2)，空间复杂度O(n^2)
            还有一种可以把空间内复杂度变成O(m+n)，就是用两个set存储原数组中出现0的行和列，最后一起置零即可
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        set<int> x;
        set<int> y;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(matrix[i][j]==0){
                    x.insert(i);
                    y.insert(j);
                }
            }
        }
        for(auto it = x.begin(); it != x.end(); ++it){
            for(int k = 0; k < m; ++k){
                matrix[*it][k] = 0;
            }
        }
        for(auto it = y.begin(); it != y.end(); ++it){
            for(int k = 0; k < n; ++k){
                matrix[k][*it] = 0;
            }
        }
        return;
    }
};