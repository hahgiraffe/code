/*
 * @Author: haha_giraffe
 * @Date: 2019-12-02 22:21:21
 * @Description: 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 */

/* 
    解题思路：首先试试蛮力法，发现会超时，就改用递归求解，关键点在于每次一半
*/
class Solution {
public:
    double fastdfs(double x, long long N){
        if(N == 0){
            return 1.0;
        }
        double f = fastdfs(x, N/2);
        if(N % 2 == 0){
            return f * f;
        }
        else{
            return f * f * x;
        }
    }
    double myPow(double x, int n) {
        //暴力会超时,所以只能递归孔家二分
        long long N = n;
        if(N < 0){
            x = 1 / x;
            N = -N;
        }
        return fastdfs(x, N);
    }
};