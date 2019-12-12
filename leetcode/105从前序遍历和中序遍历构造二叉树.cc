/*
 * @Author: haha_giraffe
 * @Date: 2019-12-12 21:42:19
 * @Description: 根据前序遍历和中序遍历构造二叉树
 */
/* 
    解题思路：这题目很重要，经常考，重点在于搞清楚dfs边界，思路很简单，首先在preorder中left找根节点，然后在inorder中遍历查找，把其分成左右两步分别dfs
*/

class Solution {
public:
    TreeNode* dfs(vector<int>& preorder, int preleft, int preright, vector<int>& inorder, int inleft, int inright){
        TreeNode* newnode = new TreeNode(preorder[preleft]);
        int i = inleft;
        for(i = inleft; i<=inright; ++i){
            if(inorder[i] == preorder[preleft]){
                break;
            }
        }
        int llen = i - inleft;
        int rlen = inright - i;
        if(llen > 0) newnode->left = dfs(preorder, preleft + 1, preleft + llen, inorder, inleft, inleft + llen - 1);
        if(rlen > 0) newnode->right = dfs(preorder, preleft + llen + 1, preright, inorder, inleft + llen + 1, inright);
        return newnode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()){
            return NULL;
        }
        return dfs(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};