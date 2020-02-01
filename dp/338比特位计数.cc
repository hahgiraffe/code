/*
 * @Author: haha_giraffe
 * @Date: 2020-02-01 09:24:39
 * @Description: 给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。
 */
/* 
    解题思路：这道题目将dp和比特位联系在一起，思路很特别，分成奇数和偶数。状态转移方程：奇数的1个数 = 上一个偶数中1个数 + 1。偶数的1个数 = 偶数/2的1个数
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        res[0] = 0;
        for(int i = 1; i <= num; i++){
            if(i % 2 == 1){
                res[i] = res[i-1] + 1;
            }
            else{
                res[i] = res[i/2];
            }
        }
        return res;
    }
};