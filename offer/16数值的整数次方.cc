/*
 * @Author: haha_giraffe
 * @Date: 2020-02-20 11:06:14
 * @Description: 实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。
 */
/* 
    解题思路：这题目的思路很简单，就是一个二分的思路，可以用递归或非递归写。但是有两个点需要注意，一个是n为负数的是，另一个是n == INT_MIN的时候如果直接-n会超过范围（数值范围是 [−231, 231 − 1]）
*/
class Solution {
public:
    double dfs(double x, long long n){
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x;
        }
        if(n % 2 == 1){
            return dfs(x, n-1) * x;
        }
        else{
            double tmp = dfs(x, n / 2);
            return tmp * tmp;
        }
    }
    double myPow(double x, int n) {
        bool ism = false;
        if(n == 0 || x == 1) return 1;
        if(n < 0){
            ism = true;
        }
        long long N = n;
        if(ism){
            //注意要单独把INT_MIN拿出来
            if(n == INT_MIN) N = -(n+1);
            else{
                N = -n;
            }
        }
        double res = dfs(x, N);
        if (n==INT_MIN) res *= x;
        if(ism){
            return 1.0 / res;
        }
        return res;
    }
};

/* 
这个快速幂的方法更加容易，且不用处理INT_MIN等问题
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1) return 1;
        double res = 1;
        long long N = n;
        if(n < 0){
            N = -N;
            x = 1.0 / x;
        }
        while(N){
            if(N & 1) res *= x;
            N >>= 1;
            x *= x;
        }
        return res;
    }
};
*/