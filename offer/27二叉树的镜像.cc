/*
 * @Author: haha_giraffe
 * @Date: 2020-02-20 11:48:31
 * @Description: 二叉树的镜像
 */
class Solution {
public:
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        dfs(root->left);
        dfs(root->right);
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return;
    }
    TreeNode* mirrorTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};