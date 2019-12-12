/*
 * @Author: haha_giraffe
 * @Date: 2019-12-12 20:40:38
 * @Description: 将有序数组转换为二叉搜索树
 */
/* 
    解题思路：二分法然后将值构建二叉搜索树
*/

class Solution {
public:
    TreeNode* dfs(vector<int>& nums, int l, int r){
        if(l > r) return NULL;
        if(l == r){
            TreeNode* tmp = new TreeNode(nums[l]);
            return tmp;
        }
        int middle = l + (r-l)/2;
        TreeNode* tmp = new TreeNode(nums[middle]);
        tmp->left = dfs(nums, l, middle-1);
        tmp->right = dfs(nums, middle+1, r);
        return tmp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()){
            return NULL;
        }
        TreeNode* root = dfs(nums, 0, nums.size()-1);
        return root;
    }
};