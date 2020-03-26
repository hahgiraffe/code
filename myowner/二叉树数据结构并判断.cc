/*
 * @Author: haha_giraffe
 * @Date: 2020-03-15 12:21:14
 * @Description: 手写一个二叉树的结构，并判断是否为二叉排序树
 */
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : val(v), left(NULL), right(NULL) { }
    ~TreeNode() { }
};

void judge(TreeNode* root, bool& res){
    if(!root || res == false){
        return;
    }
    if(root->left && root->left->val > root->val){
        res = false;
        return;
    }
    if(root->right && root->right->val < root->val){
        res = false;
        return;
    }
    judge(root->left, res);
    judge(root->right, res);
}

int main(){
    TreeNode* root;
    bool res = true;
    judge(root, res);
    cout << res << endl; 
    return 0;
}