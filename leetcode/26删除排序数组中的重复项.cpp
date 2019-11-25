/*
 * @Author: haha_giraffe
 * @Date: 2019-11-01 21:05:35
 * @Description: 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
                不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
*/

/* 
    解题思路：这题目一开始没有思路，但是看到排序数组应该想到双指针的。本质上就是将重复的元素放到末尾，但是注意不能用左右指针因为前后交换会调换顺序（如果用排序中的说法就是不稳定）
    所以只能用快慢指针，将重复的去除。
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //不能用额外空间，只能原地
        if(nums.empty()){
            return 0;
        }
        int slow = 0;
        int fast = 0;
        while(fast < nums.size()){
            if(nums[slow]==nums[fast]){
                fast++;
            }
            else{
                nums[slow+1]=nums[fast];
                fast++;
                slow++;
            }
        }
        return slow+1;
    }
};