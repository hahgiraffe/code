/*
 * @Author: haha_giraffe
 * @Date: 2019-10-24 20:49:48
 * @Description: 两数相加，一个数组中找到和为target的两个数
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 */

/* 
    解题思路：用一个map存储old_value(new_value), old_index
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> res;
        for(int i=0;i<nums.size();++i){
            if(m.find(nums[i]) != m.end()){
                res.push_back(m[nums[i]]);
                res.push_back(i);
            }
            else{
                m.insert({target-nums[i],i});
            }
        }
        return res;
    }
};