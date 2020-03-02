/*
 * @Author: haha_giraffe
 * @Date: 2020-02-27 19:45:47
 * @Description: 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印
 */

/* 
    方法一：还是dfs，用一个二维数组保存每一层的节点信息
    方法二：bfs，用一个队列保存节点
*/
class Solution {
public:
    void dfs(TreeNode* root, vector<vector<int>>& vec, int level){
        if(!root){
            return;
        }
        if(level >= vec.size()){
            vec.push_back({});
        }
        vec[level].push_back(root->val);
        dfs(root->left, vec, level+1);
        dfs(root->right, vec, level+1);
    }
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        vector<vector<int>> vec;
        int level = 0;
        dfs(root, vec, level);
        for(auto a : vec){
            for(auto b : a){
                res.push_back(b);
            }
        }
        return res;
    }
    
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if(!root){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp = q.front();
            res.push_back(tmp->val);
            q.pop();
            if(tmp->left){
                q.push(tmp->left);
            }
            if(tmp->right){
                q.push(tmp->right);
            }
        }
        return res;
    }
    
};

//如果要bfs打印成一个二维数组，则先把每一层的长度挑选出来，
//dfs可以直接用上面的代码
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> tmp;
            int l = q.size();
            for(int i = 0; i < l ; ++i){
                TreeNode* n = q.front();
                q.pop();
                tmp.push_back(n->val);
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

//如果要之字形状打印
//bfs可以用deque，用一个flag表示奇偶层数，注意如果pop_front就要push_back,如果pop_back就要push_front(同时更改左右指针顺序)
//dfs直接每间隔一个reverse一下即可

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        deque<TreeNode*> d;
        d.push_back(root);
        bool flag = true;
        while(!d.empty()){
            vector<int> tmp;
            int n = d.size();
            for(int i = 0; i < n; ++i){
                if(flag){
                    TreeNode* node = d.front();
                    d.pop_front();
                    tmp.push_back(node->val);
                    if(node->left){
                        d.push_back(node->left);
                    }
                    if(node->right){
                        d.push_back(node->right);
                    }
                } else {
                    TreeNode* node = d.back();
                    d.pop_back();
                    tmp.push_back(node->val);
                    if(node->right){
                        d.push_front(node->right);
                    }
                    if(node->left){
                        d.push_front(node->left);
                    }
                }
                
            }
            flag = !flag;
            res.push_back(tmp);
        }
        return res;
    }
};