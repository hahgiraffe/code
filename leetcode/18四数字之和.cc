/*
 * @Author: haha_giraffe
 * @Date: 2019-10-30 22:50:47
 * @Description: 四数之和
 */

/*
其实方法和三数之和一样，前两个二重循环，后面双指针，复杂度O(n^3)
注意重复的要立刻移动 
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        if(nums.size()<4){
            return res;
        }
        for(int i=0;i<=nums.size()-4;++i){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<=nums.size()-3;++j){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int l=j+1;
                int r=nums.size()-1;
                while(l<r){
                    if(nums[i]+nums[j]+nums[l]+nums[r] < target){
                        l++;
                    }
                    else if(nums[i]+nums[j]+nums[l]+nums[r] > target){
                        r--;
                    }
                    else{
                        res.push_back(vector<int>{nums[i],nums[j],nums[l],nums[r]});
                        while(l<r && nums[l]==nums[l+1]){
                            l++;
                        }
                        while(l<r && nums[r]==nums[r-1]){
                            r--;
                        }
                        l++;
                        r--;
                    }
                }
            }
        }
        return res;
    }
};