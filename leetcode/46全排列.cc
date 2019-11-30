/*
 * @Author: haha_giraffe
 * @Date: 2019-11-30 09:51:46
 * @Description: 全排列
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 */
/* 
    解题思路：最简单的一个方法就是用STL的next_permutation,
            如果要自己实现，就是dfs交换即可

*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(),nums.end());
        res.push_back(nums);
        while(next_permutation(nums.begin(),nums.end())){
            res.push_back(nums);
        }
        return res;
    }
};

class Solution {
public:
    void dfs(vector<int>& nums,int i,vector<vector<int>>& res){
        if( i == nums.size()-1){
            res.push_back(nums);
            return;
        }
        for(int tmp = i; tmp<nums.size(); ++tmp){
            swap(nums[i], nums[tmp]);
            dfs(nums,i+1, res);
            swap(nums[i], nums[tmp]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        if(nums.empty() || nums.size() == 1){
            res.push_back(nums);
            return res;
        }
        sort(nums.begin(),nums.end());
        dfs(nums, 0, res);
        return res;
    }
};