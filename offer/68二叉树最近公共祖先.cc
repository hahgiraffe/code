/*
 * @Author: haha_giraffe
 * @Date: 2020-02-29 19:12:03
 * @Description: 
 */

/* 
    二叉搜索树最近公共祖先
*/
class Solution {
public:
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& res){
        if(!root){
            return;
        }
        if(res != NULL){
            return;
        }
        if(p->val == root->val || q->val == root->val){
            res = root;
            return;
        }
        if(p->val < root->val && q->val > root->val){
            res = root;
            return;
        }
        if(p->val > root->val && q->val < root->val){
            res = root;
            return;
        }
        if(p->val < root->val && q->val < root->val){
            dfs(root->left, p, q, res);
        }
        if(p->val > root->val && q->val > root->val){
            dfs(root->right, p, q, res);
        }
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = NULL;
        dfs(root, p, q, res);
        return res;
    }
};


/* 
    二叉树的最近公共祖先，给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
*/
class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root){
            return NULL;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode* t1 = dfs(root->left, p, q);
        TreeNode* t2 = dfs(root->right, p, q);
        if(t1 && t2){
            return root;
        } else if(t1){
            return t1;
        } else{
            return t2;
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};