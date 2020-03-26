/*
 * @Author: haha_giraffe
 * @Date: 2020-03-23 10:25:11
 * @Description: 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。换句话说，第一个字符串的排列之一是第二个字符串的子串。
 */

/* 
    解题思路：如果是覆盖则不行，如果仅仅是排列，用两个vector即可。
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1 > len2){
            return false;
        }
        vector<int> vec(26, 0);
        vector<int> window(26, 0);
        int left = 0, right = 0;
        for(auto a : s1){
            vec[a - 'a']++;
            window[s2[right++] - 'a']++;
        }
        if(window == vec){
            return true;
        }
        while(right < len2){
            window[s2[left++] - 'a']--;
            window[s2[right++] - 'a']++;
            if(vec == window){
                return true;
            }
        }
        return false;
    }
};