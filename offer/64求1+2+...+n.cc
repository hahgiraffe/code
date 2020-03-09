/*
 * @Author: haha_giraffe
 * @Date: 2020-03-05 12:53:47
 * @Description: 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
 */
/* 
    解题思路：因为不能用循环，所以只能用递归，递归最重要的递归结束条件，因为不能用if，所以只能用 n && x 这种方式，如果n != 0 则继续后面的，否则不执行后面的
*/
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n-1));
        return n;
    }
};