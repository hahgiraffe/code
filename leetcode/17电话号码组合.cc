/*
 * @Author: haha_giraffe
 * @Date: 2019-11-25 14:59:11
 * @Description: 电话号码的字母组合
 *  输入："23"
    输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */
/*
    解题思路：用一个map存储数字与字母映射，然后直接dfs
*/
class Solution {
public:
    map<int,string> m{
        {2,"abc"},
        {3,"def"},
        {4,"ghi"},
        {5,"jkl"},
        {6,"mno"},
        {7,"pqrs"},
        {8,"tuv"},
        {9,"wxyz"},
    };
    void dfs(vector<string>& res,string digits,int now,string& tmp){
        if(now == digits.size()){
            res.push_back(tmp);
            return;
        }
        int size = m[digits[now]-'0'].size();
        for(int i=0;i<size;++i){
            tmp +=m[digits[now]-'0'][i];
            dfs(res,digits,now+1,tmp);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()){
            return res;
        }
        string tmp ="";
        dfs(res,digits,0,tmp);
        return res;
    }
};