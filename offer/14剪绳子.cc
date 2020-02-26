/*
 * @Author: haha_giraffe
 * @Date: 2020-02-18 23:27:01
 * @Description: 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
 * 每段绳子的长度记为 k[0],k[1]...k[m] 。请问 k[0]*k[1]*...*k[m] 可能的最大乘积是多少？
 * 例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
 */

/* 
    解题思路：找规律，求3最多的个数，然后再是求4和2
*/
class Solution {
public:
    int cuttingRope(int n) {
        if(n == 2){
            return 1;
        }
        if(n == 3){
            return 2;
        }
        int res = 1;
        while(n >= 3){
            if(n == 4){
                break;
            }
            n -= 3;
            res *= 3;
        }
        if(n){
            res *= n;
        }
        return res;
    }
};

/* 
    这道题目的经典算法是DP。dp[i]表示绳子长度为i时候的最大乘积，在中间任意切分的是，可以分成k与i-k，同时i-k可以判断是否再次切分。
*/
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n+1, 0);
        dp[2] = 1;
        dp[1] = 1;
        for(int i = 3; i <= n; ++i){
            for(int k = 2; k <= i - 1; ++k){
                dp[i] = max(dp[i], max(k * (i-k), k * dp[i-k]));
            }
        }
        return dp[n];
    }
};