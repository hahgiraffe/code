/*
 * @Author: haha_giraffe
 * @Date: 2020-02-29 19:53:38
 * @Description: 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
 */
/* 
    解题思路：每两个int，转换成字符串进行比较即可
*/
class Solution {
public:
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            string stra = to_string(a);
            string strb = to_string(b);
            if(stra + strb < strb + stra){
                return true;
            }
            return false;
        });
        string res;
        for(auto a : nums){
            res += to_string(a);
        }
        return res;
    }
};