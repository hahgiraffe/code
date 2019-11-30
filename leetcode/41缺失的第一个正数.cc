/*
 * @Author: haha_giraffe
 * @Date: 2019-11-27 17:32:39
 * @Description: 缺失的第一个正数
 * 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
 */

/* 
    解题思路：这道题目思路很经典，是一个桶排序的题目，时间复杂度O(n)（因为循环每次都有一个桶确定）,空间复杂度O(1)
            主要考虑循环退出条件，当其超过范围或者有重复的就退出，最后再遍历一次查看如果相同则返回。
            有一点需要考虑的是，就是vector中存储的元素是index+1
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //桶排序
        int n = nums.size();
        for(int i=0; i<n; ++i){
            while(nums[i] != i+1){
                if(nums[i]<=0 || nums[i]> n || nums[i] == nums[nums[i]-1] ) 
                    break;
                int tmp = nums[i]-1;
                nums[i] = nums[tmp];
                nums[tmp] = tmp+1;
            }
        }
        for(int i=0;i<n;++i){
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};