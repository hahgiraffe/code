/*
 * @Author: haha_giraffe
 * @Date: 2020-03-09 15:12:34
 * @Description: 请实现两个函数，分别用来序列化和反序列化二叉树。
 */
/* 
    这个其实很简单，就是按照思路去做，序列化时，如果为空则添加'#,',否则添加','
    反序列化的时候，用一个index遍历string，如果遇到#则为空，否则先判断是否为负数，然后累加和，就可以啦
*/
class Codec {
public:
    void dfs(TreeNode* root, string& s){
        if(!root){
            s += "#,";
            return;
        }
        s += to_string(root->val) + ",";
        dfs(root->left, s);
        dfs(root->right, s);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        dfs(root, s);
        return s;
    }

    TreeNode* dfs2(string data, int& p){
        if(data[p] == '#'){
            p += 2;
            return NULL;
        }
        bool flag = false;
        if(data[p] == '-'){
            flag = true;
            p++;
        }
        int n = 0;
        while(data[p] != ','){
            n = n * 10 + data[p] - '0';
            p++;
        }
        p++;
        if(flag){
            n = -n;
        }
        TreeNode* root = new TreeNode(n);
        root->left = dfs2(data, p);
        root->right = dfs2(data, p);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int p = 0;
        return dfs2(data, p);
    }
};