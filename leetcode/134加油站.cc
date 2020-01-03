/*
 * @Author: haha_giraffe
 * @Date: 2019-12-31 21:44:27
 * @Description: 环形路上加油站
 */
/* 
    解题思路：首先判断能不能有解答（根据原理分析，只要sum(gas) >= sum(cost) 就一定会有解答）
            然后用一个tmp指标表示当前剩余油量，如果到某个站点tmp < 0 则以下一个站点为起点重新开始遍历累加
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res1 = accumulate(gas.begin(), gas.end(), 0);
        int res2 = accumulate(cost.begin(), cost.end(), 0);
        if(res1 < res2){
            return -1;
        }
        int tmp = 0;
        int res = 0;
        for(int i=0; i<gas.size(); ++i){
            tmp += gas[i] - cost[i];
            if(tmp < 0){
                tmp = 0;
                res = i+1;
            }
        }
        return res;
    }
};