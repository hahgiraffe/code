/*
 * @Author: haha_giraffe
 * @Date: 2019-11-30 10:11:03
 * @Description: 顺时针旋转图像90°,不允许用另一个矩阵赋值
 */

/* 
    解题思路一：这道题目就是知道解题思路就很好做，按部就班
            首先要想好一圈一圈走（leftupx,leftupy,n就可以实现），然后一圈中还要循环遍历即可（循环i可以实现）
    解题思路二：先矩阵按照主对角线转置，然后在镜像翻转即可

    如果是逆时针旋转90°呢？可以先按照次对角线转置，然后再镜像翻转即可

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int leftupx = 0;
        int leftupy = 0;
        while(n > 1){
            for(int i = 0; i< n-1; ++i){
                int tmp = matrix[leftupx][i+leftupy];
                matrix[leftupx][i+leftupy] = matrix[leftupx+n-1-i][leftupy];
                matrix[leftupx+n-1-i][leftupy] = matrix[leftupx+n-1][leftupy+n-1-i];
                matrix[leftupx+n-1][leftupy+n-1-i] = matrix[leftupx+i][leftupy+n-1];
                matrix[leftupx+i][leftupy+n-1] = tmp;
            }
            leftupx++;
            leftupy++;
            n -= 2;
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //先转置再翻转
        for(int i=0; i<n; ++i){
            for(int j=0; j<i; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i=0; i<n; ++i){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
