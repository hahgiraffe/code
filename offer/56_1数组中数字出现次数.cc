/*
 * @Author: haha_giraffe
 * @Date: 2020-03-05 10:18:47
 * @Description: 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
 */

/* 
    这种类型的题目有三种，第一种就是数组中只有一个数字出现一次，其余数字出现两次，要找到出现一次的数字，方法就是全部异或即可。
    第二种就是本题，数组中有两个数字出现一次，其余数字出现两次，思路就是将数组分成两组，每一组包含一个只出现一次的数字，同时相同的数字要分在一组。
    解决方法就是首先所有数字异或，结果中找到一个为1的位，以这一位进行区分，这样就可以保证上述两个条件满足。
*/

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; ++i){
            res ^= nums[i];
        }
        int a = 1;
        while(!(res & a)){
            a = a << 1;
        }
        int tmpa = 0;
        int tmpb = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] & a){
                tmpa ^= nums[i];
            } else {
                tmpb ^= nums[i];
            }
        }
        return {tmpa, tmpb};
    }
};
/*
    第三种题目，在一个数组nums中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
    解题思路：位运算，总共32位，每个数字的每一位累加起来，如果总和能mod3，则说明出现一次的数字在该位上为0，否则为1
    重点在于位运算，如果判断一个位为0或者为1，如何某个位置一等操作
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i = 0;
        int res = 0;
        int n = nums.size();
        while(i < 32){
            int tmp = 0;
            for(int j = 0; j < n; ++j){
                if (nums[j] & (1<<i)){
                    tmp += 1;
                }
            }
            if(tmp % 3 != 0){
                res |= (1<<i);
            }
            i++;
        }
        return res;
    }
};