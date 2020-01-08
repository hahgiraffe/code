/*
 * @Author: haha_giraffe
 * @Date: 2020-01-06 18:07:32
 * @Description: 颠倒给定的 32 位无符号整数的二进制位。
 */

/* 
    解题思路：位操作经典题，就是要第0位与第31位交换
    (n >> 31-i) & 1 表示取到第31-i位，
    ((n >> 31-i) & 1) << i 第31-i位再往左移动i位，则可实现换位
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for(int i = 31; i >= 0 ; --i){
            // 分别取出第31-i位放到输出数的i位
            res |= (((n >> (31-i)) & 1) << i);
        }
        return res;
    }
};