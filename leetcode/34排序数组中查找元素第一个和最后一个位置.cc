/*
 * @Author: haha_giraffe
 * @Date: 2019-11-26 11:22:05
 * @Description: 排序数组中查找元素的第一个和最后一个位置
 */

/*
    解题思路：这题是裸二分模板的左节点和右节点的综合，详见template/binary_search.md
*/
class Solution {
public:
    int findleft(vector<int>& nums, int target){
        //取得最左端点
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int middle = (r+l)/2;
            if(nums[middle] < target){
                l=middle+1;
            }
            else{
                r=middle;
            }
        }
        if(nums[l]!=target){
            return -1;
        }
        return l;
    }
    int findright(vector<int>& nums, int target){
        //查找最右端点
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int middle = (r+l+1)/2;
            if(nums[middle] > target){
                r=middle-1;
            }
            else{
                l=middle;
            }
        }
        if(nums[r]!=target){
            return -1;
        }
        return r;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return vector<int>{-1,-1};
        }
        int left = findleft(nums,target);
        if(left ==-1){
            return vector<int>{-1,-1};
        }
        int right = findright(nums,target);
        return vector<int> {left,right};
    }
};

