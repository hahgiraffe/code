/*
 * @Description: 
 * @Author: haha_giraffe
 * @Date: 2019-08-03 11:18:59
 */
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x):left(NULL),right(NULL),val(x){

    }
};
TreeNode* buildtree();
vector<int> bfs_binarytree(TreeNode *root);

vector<int> bfs_binarytree(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    vector<int> res;
    while (!q.empty())
    {
        TreeNode *tmp = q.front();
        q.pop();
        res.push_back(tmp->val);
        if (tmp->left)
            q.push(tmp->left);
        if (tmp->right)
            q.push(tmp->right);
    }
    return res;
}

TreeNode* buildtree(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(5);
    root->right=new TreeNode(8);
    return root;
}
int main()
{
    TreeNode* root=buildtree();
    vector<int> res=bfs_binarytree(root);
    for(auto a:res){
        cout<<a<<" ";
    }
    return 0;
}