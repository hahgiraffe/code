/*
 * @Author: haha_giraffe
 * @Date: 2019-12-05 20:20:42
 * @Description: 加1
 *  给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
    你可以假设除了整数 0 之外，这个整数不会以零开头。
 */

/* 
    解题思路：就是从最后往前找即可，记得处理9999的情况
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n-1;
        bool flag = false;
        while(i>=0){
            if(digits[i] != 9){
                digits[i]++;
                flag = true;
                break;
            }
            else{
                digits[i--] = 0;
            }
        }
        if(flag == false){
            vector<int> res;
            res.push_back(1);
            for(auto& i : digits){
                res.push_back(i);
            }
            return res;
        }
        return digits;
    }
};