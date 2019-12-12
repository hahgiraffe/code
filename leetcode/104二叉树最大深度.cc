/*
 * @Author: haha_giraffe
 * @Date: 2019-12-11 22:19:48
 * @Description: 二叉树最大深度
 */
/* 
    直接一个dfs即可
*/
class Solution {
public:
    void dfs(TreeNode* root, int& res, int tmp){
        if(!root) return;
        if(tmp > res) res = tmp;
        dfs(root->left, res, tmp+1);
        dfs(root->right, res, tmp+1);
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        dfs(root, res, 1);
        return res;
    }
};
