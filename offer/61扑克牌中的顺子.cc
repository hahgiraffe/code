/*
 * @Author: haha_giraffe
 * @Date: 2020-03-17 17:19:34
 * @Description: 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。
 */

/* 
    解题思路:首先排序,然后找出0的个数,接着遍历数组,如果相邻两个数相差>1,则累加差值,最后用0的个数与差值个数比较.
*/
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int num = 0;
        int i = 0;
        while(nums[i] == 0){
            num++;
            i++;
        }
        int n = nums.size();
        int res = 0;
        for(; i < n-1; ++i){
            if(nums[i + 1] == nums[i]) return false;
            if(nums[i+1] - nums[i] > 1){
                res += nums[i+1] - nums[i] - 1;
            }
        }
        return res <= num ? true : false;
    }
};