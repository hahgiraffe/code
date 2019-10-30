/*
 * @Author: haha_giraffe
 * @Date: 2019-10-29 09:33:27
 * @Description: 三数之和（不能重复）
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

 */

/*
这题目就是排序+双指针
还要注意优化策略，每当有重复的数字直接跳过，这样才能过
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.empty()){
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;++i){
            int target = -nums[i];
            int b=i+1;
            int e=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            while(b<e){
                if(nums[b]+nums[e]<target){
                    b++;
                }
                else if(nums[b]+nums[e]>target){
                    e--;
                }
                else{
                    ans.push_back({nums[i],nums[b],nums[e]});
                    while(b<e && nums[b]==nums[b+1]) b++;
                    while(b<e && nums[e]==nums[e-1]) e--;
                    b++;
                    e--;
                }
            }
        }
        return ans;
    }
};