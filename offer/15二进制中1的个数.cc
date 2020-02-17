/*
 * @Author: haha_giraffe
 * @Date: 2020-02-17 20:28:34
 * @Description: 二进制中1的个数
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){
            n = n & (n-1);
            res++;
        }
        return res;
    }
};