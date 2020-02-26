/*
 * @Author: haha_giraffe
 * @Date: 2020-02-21 22:54:22
 * @Description: 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的
 */
class Solution {
public:
    void dfs(TreeNode* f, TreeNode* s, bool& res){
        if(!f && !s){
            return;
        }
        else if(f && !s){
            res = false;
            return;
        }
        else if(!f && s){
            res = false;
            return;
        }
        if(!res){
            return;
        }
        if(f->val != s->val){
            res = false;
            return;
        }
        dfs(f->left, s->right, res);
        dfs(f->right, s->left, res);
        return;
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* f = root;
        TreeNode* s = root;
        bool res = true;
        dfs(f, s,res);
        return res;
    }
};