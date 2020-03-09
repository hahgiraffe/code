/*
 * @Author: haha_giraffe
 * @Date: 2020-03-05 10:00:39
 * @Description: 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
 */
class Solution {
public:
    int dfs(TreeNode* root, bool& res){
        if(!root){
            return 0;
        }
        int l = dfs(root->left, res);
        int r = dfs(root->right, res);
        if(abs(l - r) >= 2){
            res = false;
        }
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool res = true;
        dfs(root, res);
        return res;
    }
};