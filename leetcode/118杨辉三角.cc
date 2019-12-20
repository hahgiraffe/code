/*
 * @Author: haha_giraffe
 * @Date: 2019-12-13 22:30:09
 * @Description: 杨辉三角
 */
/* 
    解题思路：杨辉三角，就是考虑边界情况，两层循环即可
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0; i<numRows; ++i){
            vector<int> vec;
            int len = i+1;
            for(int j=0; j<len; ++j){
                if(j==0 || j==i){
                    vec.push_back(1);
                }
                else{
                    vec.push_back(res[i-1][j]+res[i-1][j-1]);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};