/*
 * @Author: haha_giraffe
 * @Date: 2020-02-06 10:07:24
 * @Description: 最后一块石头的重量
 * 有一堆石头，每块石头的重量都是正整数。
 * 每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块石头。返回此石头最小的可能重量。如果没有石头剩下，就返回 0。

 */
/* 
    解题思路：一开始想到用贪心法，每次找两个最近石头的碰撞，发现不行。
            后面发现可以理解为01背包的DP。将石头分成两堆，目标是两堆和的差最小（如何使两堆石头总重量接近 sum / 2）。
            所以限制条件就是sum / 2，dp[i] 背包容量限制为 i 时能够装载的最大石块总重量
*/

class Solution {

public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for(int i = 0 ; i < n; ++i){
            int cur = stones[i];
            for(int j = target; j >= cur ; j--){
                dp[j] = max(dp[j], dp[j - cur] + cur);
            }
        }
        return sum - 2*dp[target];
    }
};