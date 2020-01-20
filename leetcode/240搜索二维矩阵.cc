/*
 * @Author: haha_giraffe
 * @Date: 2020-01-16 20:42:18
 * @Description: 搜索二维矩阵
 * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：
 * 每行的元素从左到右升序排列。
 * 每列的元素从上到下升序排列。
 */

/* 
    解题思路：这道题很经典，可以用二分，但是剪枝是最简单的，只能从右上角或者左下角开始，一直遍历即可。
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        //右上角开始剪枝
        int x = 0, y = m-1;
        while(x < n && y >=0){
            if(target == matrix[x][y]){
                return true;
            }
            else if(target < matrix[x][y]){
                y -= 1;
            }
            else{
                x += 1;
            }
        }
        return false;
    }
};