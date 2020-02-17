/*
 * @Author: haha_giraffe
 * @Date: 2020-02-15 23:48:48
 * @Description: 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 
    解题思路：首先要根据前序遍历找到根节点，然后在中序遍历中找到左边有几个节点，再以此划分
    重点在于，中序遍历和前序遍历都要有自己的开始和末尾的index
*/
class Solution {
public:
    TreeNode* dfs(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int ins, int ine){
        if(ps > pe || ins > ine){
            return NULL;
        }
        if(ps == pe || ins == ine){
            return new TreeNode(preorder[ps]);
        }
        int tmp = preorder[ps];
        int i = ins;
        for(i = ins; i <= ine; ++i){
            if(inorder[i] == tmp){
                break;
            }
        }
        int llen = i - ins;
        // int rlen = ine - i;
        TreeNode* node = new TreeNode(tmp);
        node->left = dfs(preorder, ps + 1, ps + llen, inorder, ins, ins + llen - 1);
        node->right = dfs(preorder, ps + llen + 1, pe, inorder, ins + llen + 1, ine);
        return node;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0){
            return NULL;
        }
        return dfs(preorder, 0, inorder.size() - 1,inorder, 0, inorder.size() - 1);
    }
};