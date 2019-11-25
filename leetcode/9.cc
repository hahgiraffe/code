/*
 * @Author: haha_giraffe
 * @Date: 2019-10-25 11:03:00
 * @Description: 判断一个整数是否为回文数
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 */


/* 
    解题思路：最简单就是转换成字符串，然后双指针，如果不能转换成字符串，就用整数反转 
*/
class Solution {
public:
    bool isPalindrome(int x) {
        //不转换为字符串的话就是普通的整数反转，利用回文数正反都是相同的性质
        string s = to_string(x);
        int len = s.size();
        int l=0,r=len-1;
        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};