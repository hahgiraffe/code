/*
 * @Author: haha_giraffe
 * @Date: 2020-02-29 21:03:32
 * @Description: 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。
 */
class Solution {
public:
    char firstUniqChar(string s) {
        int n = s.size();
        map<int, int> m;
        for(auto a : s){
            m[a - 'a']++;
        }
        for(auto a : s){
            if(m[a - 'a'] == 1){
                return a;
            }
        }
        return ' ';
    }
};