/*
 * @Author: haha_giraffe
 * @Date: 2020-01-16 21:37:59
 * @Description: 寻找重复数
 * 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
 */
/* 
    解题思路：这题很经典，一开始最容易想到排序（时间Ologn）和用set存储（空间On）都不太好
    最好的方法用二分来做，不是在index上二分，而是在值域上二分。比如数组大小为5则范围在1-4，可以直接二分找中点，然后遍历数组查找比中点小的数个数，以此继续二分
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + (r - l)/2;
            int count = 0;
            for(auto a : nums){
                if(a <= mid){
                    count++;
                }
            }
            if(count <= mid){
                l = mid + 1;
            }
            else{
                r =  mid;
            }
        }
        return l;
    }
};