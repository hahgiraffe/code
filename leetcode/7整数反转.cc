/*
 * @Author: haha_giraffe
 * @Date: 2019-10-25 10:52:40
 * @Description: 整数反转
 * 输入: 123
 * 输出: 321
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
 */

/* 
    题目解析：这道题目思路很简单，主要就是考虑溢出的方法，如果有溢出情况，最好用long来表示，
*/
class Solution {
public:
    // int reverse(int x) {
    //     int res=0;
    //     while(x){
    //         int tmp = x%10;
    //         x=x/10;
    //         if(res > INT_MAX/10 || (res == INT_MAX/10 && tmp>7)) return 0;
    //         if(res < INT_MIN/10 || (res == INT_MAX/10 && tmp<-8)) return 0;
    //         res = res*10 + tmp;
    //     }
    //     return res;
    // }
    int reverse(int x)
    {
        int max = 0x7fffffff, min = 0x80000000;//int的最大值最小值
        long rs = 0;//用long类型判断溢出
        for(;x;rs = rs*10+x%10,x/=10);//逆序，正负通吃，不用单独考虑负值
        return rs>max||rs<min?0:rs;//超了最大值低于最小值就返回0
    }
};