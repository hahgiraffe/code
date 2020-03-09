/*
 * @Author: haha_giraffe
 * @Date: 2020-03-05 20:24:28
 * @Description: 假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
 */
/* 
    dp[i]表示，在第i天（进行卖）的最大利润，
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }
        int n = prices.size();
        
        vector<int> dp(n, -1);
        dp[0] = 0;
        int res = 0;
        for(int i = 1; i < n; ++i){
            int tmp = dp[i-1] + (prices[i] - prices[i-1]);
            if(tmp < 0){
                tmp = 0;
            }
            dp[i] = tmp;
            res = max(res, dp[i]);
        }
        return res;
    }
};