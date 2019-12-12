/*
 * @Author: haha_giraffe
 * @Date: 2019-12-11 22:00:46
 * @Description: 二叉树层次遍历
 */
/* 
    解题思路：第一种方法就是用递归，但是通过记录level值来判断是哪一次层核心思路如果level >= res.size() 则插入一个新level
*/
class Solution {
public:
    void dfs(TreeNode* root, int level, vector<vector<int>>& res){
        if(!root){
            return;
        }
        if(res.size() <= level){
            res.push_back({});
        }
        res[level].push_back(root->val);
        dfs(root->left, level+1, res);
        dfs(root->right, level+1, res);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        int level = 0;
        dfs(root,level,res);
        return res;
    }
};

/* 
    解题思路2：用迭代法，也就是用queue进行层次遍历，重点在于记录每一层的节点数
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> vec;
            while(n--){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                vec.push_back(tmp->val);
            }
            res.push_back(vec);
        }
        return res;
    }
};