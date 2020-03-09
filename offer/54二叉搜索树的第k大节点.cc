/*
 * @Author: haha_giraffe
 * @Date: 2020-03-02 23:46:24
 * @Description: 
 */
/* 
    解题思路：二叉搜索树的中序遍历是从小到大，要求第k大节点，就可以逆中序（right和left反过来）
*/
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& vec){
        if(!root){
            return;
        }
        dfs(root->left, vec);
        vec.push_back(root->val);
        dfs(root->right, vec);
    }
    int kthLargest(TreeNode* root, int k) {
        vector<int> vec;
        dfs(root, vec);
        return vec[vec.size() - k];
    }
};