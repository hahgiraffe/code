/*
 * @Author: haha_giraffe
 * @Date: 2020-03-02 14:31:39
 * @Description: 我们把只包含因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
 */
/* 
    解题思路：用一个数组存储第n个丑数，然后2,3,5各一个index，比较最小的并且加1，注意6,10这种，如果是两个数的倍数，两个数都要加1
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> vec(n, -1);
        vec[0] = 1;
        int idx2 = 0, idx3 = 0, idx5 = 0;
        for(int i = 1; i < n; ++i){
            int tmp2 = vec[idx2] * 2;
            int tmp3 = vec[idx3] * 3;
            int tmp5 = vec[idx5] * 5;
            vec[i] = min(tmp2, min(tmp3, tmp5));
            if(vec[i] == tmp2) idx2++;
            if(vec[i] == tmp3) idx3++;
            if(vec[i] == tmp5) idx5++;
        }
        return vec.back();
    }
};