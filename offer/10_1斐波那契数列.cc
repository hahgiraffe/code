/*
 * @Author: haha_giraffe
 * @Date: 2020-08-05 11:09:56
 * @Description: 斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
 */
const int MOD = 1e9+7;
class Solution {
public:
    int fib(int n) {
        long long a = 0, b = 1;
        if (n == 0){
            return a;
        } else if(n == 1){
            return b;
        }
        long long tmp;
        for(int i = 2; i <= n; ++i){
            tmp = (a + b) % MOD;
            a = b;
            b = tmp;
        }
        return tmp % MOD;
    }
};