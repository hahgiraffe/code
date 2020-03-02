/*
 * @Author: haha_giraffe
 * @Date: 2020-02-27 21:14:47
 * @Description: 输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
 */
/* 
    解题思路：直接dfs即可
*/
class Solution {
public:
    void dfs(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& vec){
        if(!root){
            return;
        }
        vec.push_back(root->val);
        if(!root->left && !root->right && accumulate(vec.begin(), vec.end(), 0) == sum){
            res.push_back(vec);
            vec.pop_back();
            return;
        }
        if(root->left){
            dfs(root->left,sum, res, vec);
        }
        if(root->right){
            dfs(root->right, sum, res, vec);
        }
        vec.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> vec;
        vector<vector<int>> res;
        dfs(root, sum, res, vec);
        return res;
    }
};