/*
 * @Author: haha_giraffe
 * @Date: 2020-03-02 15:07:13
 * @Description: 二分
 */

/* 
    统计一个数字在排序数组中出现的次数。二分找左端点。然后再遍历
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0] == target ? 1 : 0;
        int l = 0, r = n-1;
        while(l < r){
            int mid = l + (r - l)/2;
            if(nums[mid] >= target){
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int num = 0;
        while(l < n && nums[l++] == target) num++;
        return num;
    }
};

/* 
    0～n-1中缺失的数字
    一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
*/

/* 
    解题思路：也是类似二分找左端点，如果nums[mid] != mid则说明目标小于等于，否则就是大于
    最后还要判断一下是否是最大的数字
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n = nums.size();
        // for(int i = 0; i < n; ++i){
        //     if(i != nums[i]){
        //         return i;
        //     }
        // }
        // return n;
        int n = nums.size();
        int l = 0, r = n-1;
        int mid = 0;
        while(l < r){
            mid = l + (r - l)/2;
            if(nums[mid] != mid){
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l == nums[l] ? n : l;
    }
};