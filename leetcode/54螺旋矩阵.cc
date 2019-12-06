/*
 * @Author: haha_giraffe
 * @Date: 2019-12-02 23:33:04
 * @Description: 螺旋矩阵
 */
/* 
    解题思路：死方法，技巧在于要找好边界条件，一步一步减小
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int n = matrix.size();
        int m = matrix[0].size();
        if(n==0 || m==0 ) return res;
        int u = 0, d = n-1, l = 0, r = m-1;
        while(1){
            for(int i = l; i<=r; ++i) res.push_back(matrix[u][i]);
            if(++u > d) break;
            for(int i = u; i<=d; ++i) res.push_back(matrix[i][r]);
            if(--r < l) break;
            for(int i = r; i>=l; --i) res.push_back(matrix[d][i]);
            if(--d < u) break;
            for(int i = d; i>=u; --i) res.push_back(matrix[i][l]);
            if(++l > r) break;
        }
        return res;
    }
};