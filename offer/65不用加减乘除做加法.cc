/*
 * @Author: haha_giraffe
 * @Date: 2020-03-03 09:39:12
 * @Description: 
 */

/* 
    解题思路：不能用加减乘除，就只能用&和^，两个数^表示不管进位的加法结果，两个数&表示进位，同时还需要左移一位，循环即可
    unsigned int 是处理负数的情况
*/
class Solution {
public:
    int add(int a, int b) {
        while(a){
            int tmp = a ^ b;
            a = ((unsigned int)(a & b)) << 1;
            b = tmp;
        }
        return b;
    }
};