/*
 * @Author: haha_giraffe
 * @Date: 2020-02-21 23:20:01
 * @Description: 
 */
/* 
    顺时针打印，记下这个
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return {};
        }
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> res;
        int u = 0, d = n-1, l = 0, r = m-1;
        while(1){
            for(int i = l; i <= r; ++i){
                res.push_back(matrix[u][i]);
            }
            u++;
            if(u > d) break;
            for(int i = u; i <= d; ++i){
                res.push_back(matrix[i][r]);
            }
            r--;
            if(r < l) break;
            for(int i = r; i >= l; --i){
                res.push_back(matrix[d][i]);
            }
            d--;
            if(d < u) break;
            for(int i = d; i >= u; --i){
                res.push_back(matrix[i][l]);
            }
            l++;
            if(l > r) break;
        }
        return res;
    }
};