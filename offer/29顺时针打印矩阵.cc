/*
 * @Author: haha_giraffe
 * @Date: 2020-02-21 23:20:01
 * @Description: 
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
        int k = 0;
        while(true){
            int sz = res.size();
            for(int i = k; i < m - k; ++i){
                res.push_back(matrix[k][i]);
            }
            if(res.size() == n * m){
                break;
            }
            for(int i = 1 + k; i < n - 1 - k; ++i){
                res.push_back(matrix[i][m-1-k]);
            }
            if(res.size() == n * m){
                break;
            }
            for(int i = m-1-k; i >= k; --i){
                res.push_back(matrix[n-1-k][i]);
            }
            if(res.size() == n * m){
                break;
            }
            for(int i = n-2-k; i> k; --i){
                res.push_back(matrix[i][k]);
            }
            if(res.size() == n * m){
                break;
            }
            k++;
        }
        return res;
    }
};