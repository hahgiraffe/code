/*
 * @Author: haha_giraffe
 * @Date: 2020-03-21 11:29:22
 * @Description: 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符
 */
/* 
    解题思路：dp[i][j]表示字符串s1[i]与s2[j]的编辑距离。这道题，主要注意初始化这里，
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        if(len1==0){
            return len2;
        }
        if(len2 == 0){
            return len1;
        }
        vector<vector<int>> dp(len1,vector<int>(len2,0));
        if(word1[0]!=word2[0]){
            dp[0][0]=1;
        }
        //初始化这里有坑啊
        int flag = false;
        for(int i=1;i<len1;++i){
            if(word1[i]==word2[0] && flag == false){
                dp[i][0]=dp[i-1][0];
                flag = true;
            }
            else dp[i][0]=dp[i-1][0]+1;
        }
        flag = false;
        for(int j=1;j<len2;++j){
            if(word1[0]==word2[j] && flag == false){
                dp[0][j]=dp[0][j-1];
                flag = true;
            }
            else dp[0][j]=dp[0][j-1]+1;
        }
        for(int i=1;i<len1;++i){
            for(int j=1;j<len2;++j){
                if(word1[i]==word2[j]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                }
            }
        }
        return dp[len1-1][len2-1];
    }
};