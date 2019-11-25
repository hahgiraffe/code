/*
 * @Author: haha_giraffe
 * @Date: 2019-10-24 20:53:19
 * @Description: 无重复字符的最长子串
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 */

/* 
    解题思路：双指针，如果两个指针之间没有重复字符，则右指针右移（同时记录对比result最大值），如果有则左指针右移，
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //双指针
        int left = 0;
        int right = 0;
        int n = s.size();
        set<char> ms;
        int res = 0;
        while(left<n && right<n){
            while(right<n && ms.find(s[right]) == ms.end()){
                ms.insert(s[right]);
                right++;
                res = max(res,(int)ms.size());
            }
            ms.erase(s[left]);
            left++;
        }
        return res;
        
    }
};