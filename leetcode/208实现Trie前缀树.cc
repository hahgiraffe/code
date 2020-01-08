/*
 * @Author: haha_giraffe
 * @Date: 2020-01-06 20:12:10
 * @Description: 实现前缀树（字典树）
 */
    
/* 
    前缀树（又称为单词查找树），用公共父节点存储字符串前缀，主要用于统计，排序和保存大量的字符串
    重点在于TrieNode节点数据结构，还有isword表达是否为一个单词
*/

//字典树数据结构
class TrieNode{
public:
    TrieNode(){
        memset(next, 0, sizeof(next));
        isword = false;
    }
    ~TrieNode(){
        for(int i=0; i<26; ++i){
            if(next[i]){
                delete next[i];
            }
        }
    }
    TrieNode* next[26]; //有26个next指针表示26个字母
    bool isword;    //是否为一个单词
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* ptr = root;
        for(auto a : word){
            if(ptr->next[a - 'a'] == NULL){
                ptr->next[a - 'a'] = new TrieNode();
            }
            ptr = ptr->next[a - 'a'];
        }
        ptr->isword = true;   //最后记住要把当前位置标为有单词
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* ptr = root;
        for(auto a : word){
            if(ptr->next[a - 'a']){
                ptr = ptr->next[a - 'a'];
            }
            else{
                return false;
            }
        }
        if(ptr->isword) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* ptr = root;
        for(auto a : prefix){
            if(ptr->next[a - 'a']){
                ptr = ptr->next[a-'a'];
            }
            else{
                return false;
            }
        }
        return true;
    }
    
private:
    TrieNode* root;
};
