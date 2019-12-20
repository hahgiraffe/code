/*
 * @Author: haha_giraffe
 * @Date: 2019-12-13 22:22:58
 * @Description: 填充每个节点的下一个右侧节点指针
 */
/* 
    解题思路：这题一看其实没有指向父节点的指针，所以只有前序遍历，先构造好上一层的next，下一层才可以继续遍历
*/

class Solution {
public:
    void dfs(Node* root){
        if(!root) return;
        if(root->right){
            if(root->left){
                root->left->next = root->right;
            }
            if(root->next){
                root->right->next = root->next->left;
            }
        }
        else{
            if(root->left && root->next){
                root->left->next = root->next->left;
            }
        }
        dfs(root->left);
        dfs(root->right);
    }
    Node* connect(Node* root) {
        if(!root) return root;
        root->next = NULL;
        dfs(root);
        return root;
    }
};