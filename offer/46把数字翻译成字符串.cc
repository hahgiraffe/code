/*
 * @Author: haha_giraffe
 * @Date: 2020-02-29 20:26:43
 * @Description: 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
 * 一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
 */
/* 
    解题思路：是一道dp，dp[i]表示字符串0-i可能的翻译方法，注意考虑0的情况，两个字符一定要是“10”-“25”
*/
class Solution {
public:
    int translateNum(int num) {
        string strnum = to_string(num);
        int n = strnum.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        vector<int> dp(n, -1);
        dp[0] = 1;
        if(strnum.substr(0,2) < "26" && strnum[0] != '0'){
            dp[1] = 2;
        } else {
            dp[1] = 1;
        }
        for(int i = 2; i < n; ++i){
            if(strnum.substr(i-1,2) < "26" && strnum[i-1] != '0'){
                dp[i] = dp[i-2] + dp[i-1];
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[n-1];
    }
};