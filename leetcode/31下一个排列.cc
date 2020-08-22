/*
 * @Author: haha_giraffe
 * @Date: 2020-08-21 21:28:37
 * @Description: 
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

 */

/* 
    解题思路：从右边往左边遍历，找到nums[i] < nums[i+1]
    然后从ｉ－> n遍历，找到比nums[i] 大，且最小的nums[j]，交换nums[i]和nums[j]，然后排序nums[i+1]以后的数据
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool find = false;
        int n = nums.size();
        int i = n-1;
        for(; i > 0; --i){
            if(nums[i-1] < nums[i]){
                find = true;
                break;
            }
        }
        if(!find){
            sort(nums.begin(), nums.end());
            return;
        }
        int tmp = nums[i-1];
        int dif = nums[i] - tmp;
        int index = i;
        for(int j = i+1; j < n; ++j){
            if(nums[j] > tmp && nums[j] - tmp < dif){
                dif = nums[j] - tmp;
                index = j;
            }
        }
        nums[i-1] = nums[index];
        nums[index] = tmp;
        sort(nums.begin() + i, nums.end());
    }
};