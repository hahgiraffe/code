/*
 * @Author: haha_giraffe
 * @Date: 2019-10-25 09:51:12
 * @Description: 最长回文子串
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 */

/*
 这题目要注意一点就是，len的开始值为3，是为了最后s.str()里面的参数，所以right要为left+len-1
 还有就是这里的dp可以直接为bool，表示dp[i][j]是否为回文
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int maxleft = 0;
        int maxlen = 1;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            if(i+1<n && s[i]==s[i+1]){
                dp[i][i+1]=1;
                maxleft = i;
                maxlen =2;
            }
        }
        for(int len = 3;len<=n;++len){
            for(int left = 0;left+len-1<n;++left){
                int right = left+len-1;
                if(s[left]==s[right] && dp[left+1][right-1]){
                    dp[left][right]=1;
                    maxleft = left;
                    maxlen = len;
                }
            }
        }
        return s.substr(maxleft,maxlen);
    }
};