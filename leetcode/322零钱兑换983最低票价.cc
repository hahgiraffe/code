/*
 * @Author: haha_giraffe
 * @Date: 2020-01-31 11:56:19
 * @Description: 322和983是一种思路
 */
/* 
    322:给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
    解题思路：因为题目要求最少，基本上是用dp可以解决，每到一个数值，查看其能由小于其的硬笔值最小达到。
*/
class Solution {
public:
    //这个问题太常考了
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        if(coins.empty()) return -1;
        vector<int> dp(amount+1, 1000000);
        dp[0] = 0;
        // for(auto& a : coins){
        //     dp[a] = 1;
        // }
        for(int i = 1; i <= amount; ++i){
            for(auto& a : coins){
                if(i >= a) dp[i] = min(dp[i - a] + 1, dp[i]);
            }
        }
        if(dp[amount] == 1000000) return -1;
        return dp[amount];
    }
};

/* 
    983:在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行。在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出。每一项是一个从 1 到 365 的整数。
    火车票有三种不同的销售方式：
    一张为期一天的通行证售价为 costs[0] 美元；
    一张为期七天的通行证售价为 costs[1] 美元；
    一张为期三十天的通行证售价为 costs[2] 美元。
    通行证允许数天无限制的旅行。 例如，如果我们在第 2 天获得一张为期 7 天的通行证，那么我们可以连着旅行 7 天：第 2 天、第 3 天、第 4 天、第 5 天、第 6 天、第 7 天和第 8 天。
    返回你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费。

    解题思路：基本上和上题一样，每到一个点，由之前的点可以达到此点的最小值(注意越界问题)
*/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, 100000);
        dp[0] = 0;
        for(int i = 1; i <= 365; ++i){
            if(find(days.begin(), days.end(), i) == days.end()){
                dp[i] = dp[i-1];
                continue;
            }
            dp[i] = min(dp[i], dp[i-1] + costs[0]);
            if(i < 7){
                dp[i] = min(dp[i], dp[0] + costs[1]);
            }
            else if(i < 30){
                dp[i] = min(min(dp[i], dp[i-7] + costs[1]), dp[0] + costs[2]);
            }
            else{
                dp[i] = min(min(dp[i], dp[i-7] + costs[1]), dp[i-30] + costs[2]);
            }
        }
        return dp[365];
    }
};