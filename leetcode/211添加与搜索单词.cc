/*
 * @Author: haha_giraffe
 * @Date: 2020-01-06 21:21:40
 * @Description: 添加和搜索单词
 */
/* 
    解题思路：字典树的典型应用，搜索字符串，这里注意，因为有'.'所以需要搜索的时候dfs遍历搜索，dfs就要注意递归退出条件
            还有TrieNode的数据结构不仅有TrieNode* next[26],还有isword
*/

class TrieTree{
public:
    TrieTree(){
        memset(next, 0, sizeof(next));
        isword = false;
    }
    ~TrieTree(){
        for(int i = 0; i < 26; ++i){
            if(next[i]){
                delete next[i];
            }
        }
    }
    TrieTree* next[26];
    bool isword;
};



class WordDictionary {
public:
    //字典树 + dfs
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieTree();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieTree* tmp = root;
        for(auto a : word){
            if(!tmp->next[a - 'a']){
                tmp->next[a - 'a'] = new TrieTree();
            }
            tmp = tmp->next[a - 'a'];
        }
        tmp->isword = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool dfs(TrieTree* root,string word,int i){
        if(!root) return false;
        if(i >= word.size()) return root->isword;
        if(word[i]!='.'){
            if(root->next[word[i]-'a'])
                return dfs(root->next[word[i]-'a'],word,i+1);
            else 
                return false;
        }
        for(int j = 0;j<26;++j){
            if(root->next[j]&&dfs(root->next[j],word,i+1)){
                return true;
            }
        }
        return false;
    }

    bool search(string word){
        return dfs(root, word, 0);
    }
    
private:
    TrieTree* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */