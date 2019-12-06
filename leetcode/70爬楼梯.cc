/*
 * @Author: haha_giraffe
 * @Date: 2019-12-05 20:31:35
 * @Description: 爬楼梯
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 */

/* 
    解题思路：典型dp dp[i] = dp[i-1] + dp[i-2] 空间复杂度还可以优化从O(n) -> O(1)
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n,0);
        if(n == 1){
            return 1;
        }
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;++i){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }
};