/*
 * @Author: haha_giraffe
 * @Date: 2020-02-28 20:28:08
 * @Description: permutation
 */
/* 
    解决方法：递归，每一个字符与后面的交换，注意因为要去重，所以最后sort一下，然后erase+unique
*/
class Solution {
public:
    void dfs(int index, string s, vector<string>& res){
        if(index == s.size()){
            res.push_back(s);
            return;
        }
        for(int i = index; i < s.size(); ++i){
            swap(s[i], s[index]);
            dfs(index+1, s, res);
        }
    }
    vector<string> permutation(string s) {
        vector<string> res;
        int n = s.size();
        dfs(0, s, res);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
/* 
    解决方法二:如果可以用next_permutation直接用就好，注意前面要sort，否则不全
*/
class Solution {
public:
    vector<string> permutation(string s){
        vector<string> res;
        sort(s.begin(), s.end());
        res.push_back(s);
        while(next_permutation(s.begin(), s.end())){
            res.push_back(s);
        }
        return res;
    }
};