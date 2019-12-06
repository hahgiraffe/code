/*
 * @Author: haha_giraffe
 * @Date: 2019-12-05 20:20:42
 * @Description: x的平方根。
 * 实现 int sqrt(int x) 函数。计算并返回 x 的平方根，其中 x 是非负整数。由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 */

/* 
    解题思路：这道题目其实是一个二分最初的模板进行一点改进（1～x有序且要找到其中一个值），主要在于要看出是二分
*/
class Solution {
public:
    int mySqrt(int x) {
        int l=1;
        int r=x;
        while(l<=r){
            int middle=l+(r-l)/2;
            if(middle== x/middle){
                return middle;
            }
            else if(middle > x/middle){
                r=middle-1;
            }
            else{
                if( (middle+1) > x/(middle+1) ){
                    return middle;
                }
                l=middle+1;
            }
        }
        return 0;
    }
};