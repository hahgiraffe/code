/*
 * @Author: haha_giraffe
 * @Date: 2019-12-06 21:16:39
 * @Description: 子集
 */

/* 
    解题思路：这种遍历完全的题目，可以和permutation类比，就是dfs，每个节点就是加进和不加进的状态
*/

class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& tmp, vector<int>& nums, int index){
        if(index>=nums.size()){
            res.push_back(tmp);
            return;
        }
        dfs(res,tmp,nums,index+1);  //不加
        tmp.push_back(nums[index]);
        dfs(res,tmp,nums,index+1);  //加
        tmp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //每个元素有两种可能，加进去与不加进去
        vector<int> tmp;
        vector<vector<int>> res;
        dfs(res,tmp,nums,0);
        return res;
    }
};