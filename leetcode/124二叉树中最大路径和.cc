/*
 * @Author: haha_giraffe
 * @Date: 2019-12-14 11:42:12
 * @Description: 二叉树中最大路径和
 */

/* 
    解题思路：这道题目要有很好的思路，首先后序遍历要返回包括该节点的最大值给上层节点，还要找一个变量记录最大值。
    对于一个节点来说，包括该节点的最大值有两种可能性，①左右子树和 + 当前节点 ②左右子树选一个最大的 + 当前节点
    注意一开始的想法，有只在左子树和右子树的最大值吗？（其实并没有，因为如果只在一个子树，那么在上一层就已经被考虑到了）
*/
class Solution {
public:
    int dfs(TreeNode* root,int& res){
        if(!root){
            return 0;
        }
        int leftmost = dfs(root->left, res);
        int rightmost = dfs(root->right, res);
        int local = root->val + max(0, max(leftmost, rightmost));   //表示经过当前节点的最大值
        res = max(res, leftmost+rightmost+root->val);
        res = max(res, local);
        return local;
        
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
};