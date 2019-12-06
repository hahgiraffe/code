/*
 * @Author: haha_giraffe
 * @Date: 2019-12-03 22:23:17
 * @Description: 跳跃游戏
 * 给定一个非负整数数组，你最初位于数组的第一个位置。数组中的每个元素代表你在该位置可以跳跃的最大长度。判断你是否能够到达最后一个位置。
 */

/* 
    解题思路：这道题就是直接算，一开始时间复杂度有点高，后面就直接考虑能跳的最远值就行
*/

class Solution {
public:
    // bool canJump(vector<int>& nums) {
    //     int size = nums.size();
    //     bool dp[size] = {false};
    //     dp[0] = true;
    //     for(int i=0; i<size; ++i){
    //         if(dp[i] == false) continue;
    //         int tmp = nums[i];
    //         for(int j = 1; j<=tmp; ++j){
    //             if(i+j<size){
    //                 dp[i+j] = true;
    //             }
    //         }
    //     }
    //     return dp[size-1];
    // }
    bool canJump(vector<int>& nums) {
        //记录能跳最大距离，每次更新，如果遍历超过则退出
        int k = 0;
        int size = nums.size();
        for(int i=0; i<size; ++i){
            if(i>k) return false;
            k = max(k, i+nums[i]);
        }
        return true;
    }
};