/*
 * @Author: haha_giraffe
 * @Date: 2020-02-27 21:45:21
 * @Description: 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
 */
/* 
    解题思路：二叉搜索树的中序遍历就是从小到大，同时最主要的是要保留一个上一个遍历节点的指针pre
*/
class Solution {
public:
    void dfs(Node* root, Node*& head, Node*& pre){
        if(!root){
            return;
        }
        dfs(root->left, head, pre);
        if(!head){
            head = root;
            pre = root;
        }
        else{
            pre->right = root;
            root->left = pre;
            pre = root;
        }
        dfs(root->right, head, pre);
    }
    Node* treeToDoublyList(Node* root) {
        if(!root){
            return NULL;
        }
        Node* head = NULL;
        Node* pre = NULL;
        dfs(root, head, pre);
        head->left = pre;
        pre->right = head;
        return head;
    }
};

//也可以这样，最后的时候再对head和tail进行连接。
class Solution {
public:
    void dfs(Node* root, Node*& pre){
        if(!root){
            return;
        }
        dfs(root->left, pre);
        if(!pre){
            pre = root;
        }
        else{
            pre->right = root;
            root->left = pre;
            pre = root;
        }
        dfs(root->right, pre);
    }
    Node* treeToDoublyList(Node* root) {
        if(!root){
            return NULL;
        }
        Node* pre = NULL;
        dfs(root, pre);
        Node* l = root;
        Node* r = root;
        while(l->left){
            l = l->left;
        }
        while(r->right){
            r = r->right;
        }
        l->left = r;
        r->right = l;
        return l;
    }
};