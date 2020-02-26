/*
 * @Author: haha_giraffe
 * @Date: 2020-02-18 23:59:13
 * @Description: 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
 */
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        int num = 1;
        while(n--){
            num *= 10;
        }
        for(int i = 1; i < num; ++i){
            res.push_back(i);
        }
        return res;
    }
};