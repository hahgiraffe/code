/*
 * @Author: haha_giraffe
 * @Date: 2019-11-28 10:09:57
 * @Description: 最长有效括号
 */

/* 
    解题思路：这道题目有很多好方法，最容易想到的就是dp。dp[i]表示以i结尾的最长有效括号，所以当s[i]=='('时候则continue
    状态转移方程，如果s[i-1] == '(' dp[i] = dp[i-2]+2; 如果s[ i-dp[i-1]-1] =='(' 则 dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2; (这里好好思考一下就知道了)
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        //dp[i]表示以s[i]结尾的字符串最长有效括号，时间复杂度O(n),空间复杂度O(n)
        int n = s.size();
        int dp[n+1]={0};
        int res = 0;
        for(int i=0; i<n; ++i){
            if(s[i]=='('){
                continue;
            }
            //s[i]==')'
            if(i-1>=0 && s[i-1] == '(') 
                dp[i] = (i>=2 ? dp[i-2] : 0 ) + 2;
            if(i-1>=0 && i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(') 
                dp[i] = dp[i-1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            res = max(res,dp[i]);
        }
        return res;
    }
};