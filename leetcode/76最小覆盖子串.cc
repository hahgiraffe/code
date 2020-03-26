/*
 * @Author: haha_giraffe
 * @Date: 2020-03-23 11:17:54
 * @Description: 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
 */
/* 
    解题思路：这道题目的思路和优化方法很经典。
    
*/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        for(auto c : t){
            map[c]++;
        }
        int left = 0, cnt = 0, maxlen = s.size() + 1, start = left;
        for(int i = 0; i < s.size(); ++i){
            if(--map[s[i]] >= 0) ++cnt;
            while(cnt == t.size()){
                if(maxlen > i - left + 1){
                    maxlen = i - left + 1;
                    start = left;
                }
                if(++map[s[left]] > 0) {
                    cnt--;
                }
                left++;
            }
        }
        return maxlen == s.size() + 1 ? "" : s.substr(start, maxlen);
    }
};