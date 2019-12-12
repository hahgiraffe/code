/*
 * @Author: haha_giraffe
 * @Date: 2019-12-11 21:32:54
 * @Description: 验证二叉搜索树
 */

/* 
    解题思路：就是中序遍历，如果觉得递归耗时可以转换成迭代
*/

class Solution {
public:
    void dfs(TreeNode* root,vector<int>& tmp){
        if(!root){
            return;
        }
        dfs(root->left, tmp);
        tmp.push_back(root->val);
        dfs(root->right, tmp);
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int> vec;
        dfs(root, vec);
        for(int i=0; i<vec.size()-1; ++i){
            if(vec[i]>=vec[i+1]){
                return false;
            }
        }
        return true;
    }
};


