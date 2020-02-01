/*
 * @Author: haha_giraffe
 * @Date: 2020-01-31 10:36:39
 * @Description: 编写一个程序，找出第 n 个丑数。丑数就是只包含质因数 2, 3, 5 的正整数。
 */
/* 
    解题思路：一开始想到可以用小根堆+set去重，后面想到可以用dp（三指针），2,3,5每个一个指针，依次累加
*/
class Solution {
public:
    // int nthUglyNumber(int n) {
    //     priority_queue<double, vector<double>, greater<double>> pq;
    //     int num = n;
    //     pq.push(1);
    //     set<double> s;
    //     double tmp;
    //     s.insert(1);
    //     while(num > 0){
    //         tmp = pq.top();
    //         pq.pop();
    //         if(s.find(tmp*2) == s.end()) {
    //             pq.push(tmp*2);
    //             s.insert(tmp*2);
    //         }
    //         if(s.find(tmp*3) == s.end()) {
    //             pq.push(tmp*3);
    //             s.insert(tmp*3);
    //         }
    //         if(s.find(tmp*5) == s.end()) {
    //             pq.push(tmp*5);
    //             s.insert(tmp*5);
    //         }
    //         num--;
    //     }
    //     return tmp;
    // }
    int nthUglyNumber(int n) {
        vector<double> dp(n+1, 0);
        dp[0] = 1;
        int idx_2 = 0, idx_3 = 0, idx_5 = 0;
        for(int i = 1; i < n; ++i){
            double tmp = min(min(dp[idx_2]*2, dp[idx_3]*3), dp[idx_5]*5);
            if(tmp == dp[idx_2]*2){
                idx_2++;
            }
            if(tmp == dp[idx_3]*3){
                idx_3++;
            }
            if(tmp == dp[idx_5]*5){
                idx_5++;
            }
            dp[i] = tmp;
        }
        return dp[n-1];
    }
};