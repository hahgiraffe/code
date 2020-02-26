/*
 * @Author: haha_giraffe
 * @Date: 2020-02-20 14:45:49
 * @Description: 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)B是A的子结构， 即 A中有出现和B相同的结构和节点值。
 */
/* 
    解题思路：直接遍历即可
*/
class Solution {
public:
    void check(TreeNode* A, TreeNode* B, bool& res){
        if(!A && B){
            res = false;
            return;
        }
        if(A && !B){
            return;
        }
        if(!A && !B){
            return;
        }
        if(A->val != B->val){
            res = false;
            return;
        }
        check(A->left, B->left, res);
        check(A->right, B->right, res); 
    }
    void dfs(TreeNode* A, TreeNode* B, bool& res){
        if(!A || res){
            return;
        }
        if(A->val == B->val){
            bool tmp = true;
            check(A, B, tmp);
            if(tmp){
                res = true;
                return;
            }
        }
        dfs(A->left, B, res);
        dfs(A->right, B, res);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B){
            return false;
        }
        bool res = false;
        dfs(A, B, res);
        return res;
    }
};