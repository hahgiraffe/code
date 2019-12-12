/*
 * @Author: haha_giraffe
 * @Date: 2019-12-11 21:44:33
 * @Description: 对称二叉树
 */

/* 
    解题思路：双指针，一个往左，一个往右，然后交换即可，注意边界条件（当有一个指针为空则返回false，只有同时为空才可以）
*/
class Solution {
public:
    void dfs(bool& res, TreeNode* l, TreeNode* r){
        if(!l && !r){
            return;
        }
        if(!r && l){
            res = false;
            return;
        }
        else if(!l && r){
            res = false;
            return;
        }
        if(l->val != r->val){
            res = false;
            return;
        }
        dfs(res, l->left, r->right);
        dfs(res, l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        TreeNode* l = root;
        TreeNode* r = root;
        bool res = true;
        dfs(res,l,r);
        return res;
    }
};

