/*
 * @Author: haha_giraffe
 * @Date: 2020-02-29 21:45:54
 * @Description: 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
 */
/* 
    解题思路：双指针，并且用一个map存储里面的字符，查看是否有重复
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> m;
        int n = s.size();
        int l = 0, r = 0;
        int res = 0;
        int num = 0;
        while(r < n){
            while(r < n){
                m[s[r] - 'a']++;
                if(m[s[r] - 'a'] == 2){
                    break;
                }
                r++;
                num++;
                res = max(res, num);
            }
            while(l < r){
                if(m[s[l] - 'a'] == 2){
                    m[s[l] - 'a']--;
                    l++;
                    break;
                } else {
                    m[s[l] - 'a']--;
                    num--;
                    l++;
                }
            }
            r++;
        }
        return res;
    }
};

/* 
最长不重复字符的字符串，用双指针+set可以完成
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int n = s.size();
        unordered_set<int> st;
        int l = 0, r = 0;
        int ans = 0;
        while(l < n){
            if(l != 0){
                st.erase(s[l-1] - 'a');
                l++;
            } else {
                l++;
            }
            while(r < n && st.count(s[r] - 'a') == 0){
                st.insert(s[r] - 'a');
                ans = max(ans, (int)st.size());
                r++;
            }
        }
        return ans;
    }
};
*/