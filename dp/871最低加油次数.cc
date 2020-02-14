/*
 * @Author: haha_giraffe
 * @Date: 2020-02-07 10:12:27
 * @Description: 汽车从起点出发驶向目的地，该目的地位于出发位置东面 target 英里处。
沿途有加油站，每个 station[i] 代表一个加油站，它位于出发位置东面 station[i][0] 英里处，并且有 station[i][1] 升汽油。
假设汽车油箱的容量是无限的，其中最初有 startFuel 升燃料。它每行驶 1 英里就会用掉 1 升汽油。
当汽车到达加油站时，它可能停下来加油，将所有汽油从加油站转移到汽车中。
为了到达目的地，汽车所必要的最低加油次数是多少？如果无法到达目的地，则返回 -1 。
注意：如果汽车到达加油站时剩余燃料为 0，它仍然可以在那里加油。如果汽车到达目的地时剩余燃料为 0，仍然认为它已经到达目的地。

 */

/* 
    解题思路：第一种方法dp,dp[i]表示i次加油后可以到达最大距离，最后只要从0遍历dp数组只要大于target就返回即可,
            状态转移就是dp[j+1]  = max(dp[j+1], dp[j] + stations[i][1]) (0<= j <= i)
*/
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long long> dp(n+1, 0);
        dp[0] = startFuel;
        for(int i = 0; i < n; ++i){
            for(int j = i; j >= 0; --j){
                if(dp[j] >= stations[i][0]){
                    dp[j+1] = max(dp[j+1], dp[j] + stations[i][1]);
                }
            }
        }
        for(int i = 0; i <= n; ++i){
            if(dp[i] >= target){
                return i;
            }
        }
        return -1;
    }
};

/* 
    解题思路：第二种方法贪心+大根堆。思想就是保留当前油量，每次当remain为负数的时候才从前面的加油站中取出最大的油量，同时res++，
*/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        int remain = startFuel;
        priority_queue<int> pq;
        int res = 0;
        //在最前面和最后加上开始0处与target，简化编码
        stations.insert(stations.begin(), {0,0});
        stations.push_back({target, 0});
        
        for(int i = 1; i <= n+1; ++i){
            remain -= stations[i][0] - stations[i-1][0];
            while(remain < 0 && !pq.empty()){
                remain += pq.top();
                pq.pop();
                res++;
            }
            if(remain < 0){
                return -1;
            }
            pq.push(stations[i][1]);
        }
        return res;
    }
};