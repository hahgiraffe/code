/*
 * @Author: haha_giraffe
 * @Date: 2019-10-26 11:25:39
 * @Description: 盛最多水的容器
 * 输入: [1,8,6,2,5,4,8,3,7]
 * 输出: 49
 */

/* 
    解题思路：双指针，left和right分别在两边，每次height小的那个向大的方向移动,min(height[left],height[right])就会增加，(right-left)就会减少，复杂度O(n)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        // 暴力方法,复杂度)(n^2)
        // int res = 0;
        // for(int i=0;i<height.size();++i){
        //     for(int j=i+1;j<height.size();++j){
        //         res = max(res,min(height[i],height[j])*(j-i));
        //     }
        // }
        // return res;
        
        int n = height.size();
        int left = 0,right = n-1;
        int res = 0;
        while( left != right){
            res = max(res,min(height[left],height[right])*(right-left));
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return res;
    }
};