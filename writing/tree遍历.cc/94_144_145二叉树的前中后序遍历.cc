/*
 * @Author: haha_giraffe
 * @Date: 2019-12-09 22:30:54
 * @Description: 二叉树的前中后序遍历
 */

/* 
    本题主要记录二叉树的前中后序的非递归遍历。总结：前中序都只用一个栈即可，后序需要两个栈，但是依旧是前序的顺序再用一个栈倒置即可。
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
    前序遍历，用栈存储节点指针，根据stack是否为空来进行判断，前序遍历是节点的入栈顺序
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        res.push_back(root->val);
        while(!s.empty()){
            while(root->left){
                root = root->left;
                res.push_back(root->val);
                s.push(root);
            }
            if(!s.empty()){
                TreeNode* tmp = s.top();
                s.pop();
                if(tmp->right){
                    root = tmp->right;
                    s.push(root);
                    res.push_back(root->val);   
                }
            }
        }
        return res;
    }
};


/* 
    中序遍历，原理和前序遍历相似，区别在于，中序遍历的顺序是节点的出栈顺序
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //二叉树非递归中序遍历记得用栈
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            while(root->left){
                root = root->left;
                s.push(root);
            }
            if(!s.empty()){
                TreeNode* tmp = s.top();
                s.pop();
                res.push_back(tmp->val);
                if(tmp->right){
                    s.push(tmp->right);
                    root = tmp->right;
                }
            }
        }
        return res;
    }
};

/* 
    后序遍历，可以用两个栈在前序遍历基础上实现，前序遍历是根左右，后序遍历是左右根，先按照前序遍历顺序放到s1中，当弹出的时候再放到s2中，最后再顺序弹出s2即可
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(!s1.empty()){
            root = s1.top();
            s1.pop();
            s2.push(root);
            if(root->left) s1.push(root->left);
            if(root->right) s1.push(root->right);
        }
        while (!s2.empty()){
            root = s2.top();
            s2.pop();
            res.push_back(root->val);
        }
        return res;
    }
};

/* 
    后序遍历，还有一个种方法只用一个stack，最后加一个reverse即可，左右根->reverse(根右左)，而左右根则可以通过前序遍历来得到（入栈顺序）
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        res.push_back(root->val);
        while(!s.empty()){
            while(root->right){
                root = root->right;
                s.push(root);
                res.push_back(root->val);
            }
            if(!s.empty()){
                TreeNode* tmp = s.top();
                s.pop();
                if(tmp->left){
                    s.push(tmp->left);
                    res.push_back(tmp->left->val);
                    root = tmp->left;   //一定要有这个重新赋值root，否则不对的
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//后序还有一个最好的方法，就是将前序的left和right调换，然后最后再reverse一次就好了
//记下这个，这个是最简单的后序方法
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        res.push_back(root->val);
        while(!s.empty()){
            while(root->right){
                root = root->right;
                s.push(root);
                res.push_back(root->val);
            }
            if(!s.empty()){
                TreeNode* tmp = s.top();
                s.pop();
                if(tmp->left){
                    s.push(tmp->left);
                    res.push_back(tmp->left->val);
                    root = tmp->left;
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

/*morris遍历，特点是非递归，不需要栈等辅助空间，O(1)空间复杂度可以完成遍历
最容易实现的就是中序遍历。步骤如下
1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。

2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。

   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。

   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。

3. 重复以上1、2直到当前节点为空。
*/
class Solution {
public:
    void morris(TreeNode* root, vector<int>& res){
        TreeNode* cur = root, *prev = NULL;
        while(cur){
            if(cur->left == NULL){
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                //find predecessor
                prev = cur->left;
                while(prev->right && prev->right != cur){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    prev->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        morris(root, res);
        return res;
    }
};