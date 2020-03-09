/*
 * @Author: haha_giraffe
 * @Date: 2020-03-05 10:01:04
 * @Description: 输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
 */
class Solution {
public:
    void dfs(TreeNode* root, int tmp, int& res){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            res = max(res, tmp);
            return;
        }
        dfs(root->left, tmp+1, res);
        dfs(root->right, tmp+1, res);
    }
    int maxDepth(TreeNode* root) {
        int res = 0;
        int tmp = 1;
        dfs(root, tmp, res);
        return res;
    }
};