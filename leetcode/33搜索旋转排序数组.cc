/*
 * @Author: haha_giraffe
 * @Date: 2019-11-26 11:05:27
 * @Description: 搜索旋转排序数组
 */

/* 
    解题思路：无重复数的二分模板，详见template/binary_search.md,
    这里有一个小变化，对于分割前之前与之后的区间要分开讨论
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //无重复的模板一
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int middle = l+(r-l)/2;
            if(nums[middle]==target){
                return middle;
            }
            else if(nums[middle]>nums[r]){
                //middle在前一部分
                if(target>nums.back()){
                    //target在前一部分
                    if(nums[middle]<target){
                        l=middle+1;
                    }
                    else{
                        r=middle-1;
                    }
                }else{
                    //target在后一部分
                    l=middle+1;
                }
            }else{
                //middle在后一部分
                if(target>nums[r]){
                    //target在前一部分
                    r=middle-1;
                }else{
                    //target在后一部分
                    if(nums[middle]<target){
                        l=middle+1;
                    }
                    else{
                        r=middle-1;
                    }
                }
            }
        }
        return -1;
    }
};
