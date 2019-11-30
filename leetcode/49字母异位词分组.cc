/*
 * @Author: haha_giraffe
 * @Date: 2019-11-30 10:51:53
 * @Description: 字母异位词分组
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 */

/* 
    解题思路：这道题目思路很清晰，首先要判断两个字符串中字符是否相同，第一个想到用set判断，但是有更好的可以用sort(str)查看是否相同
            如果相同则push_back到vector中
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string,vector<string>> m;
        for(int i=0; i<strs.size(); ++i){
            string tmpstr = strs[i];
            sort(tmpstr.begin(), tmpstr.end());
            m[tmpstr].push_back(strs[i]);
        }
        for(auto& a : m){
            res.push_back(a.second);
        }
        return res;
    }
};
