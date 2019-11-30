/*
 * @Author: haha_giraffe
 * @Date: 2019-11-27 17:23:01
 * @Description: 接雨水
 * 给定n个非负整数表示每个宽度为1的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 */
/* 
    解题思路：这题十分经典，要仔细考虑，首先遍历一遍vector找到最后的柱子，记录其高度和index，然后分别从两边往中间最高地方遍历，
    同时累加并更改最高的值。
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int mval = 0;
        int mindex = 0;
        for(int i=0;i<height.size();++i){
            if(height[i]>mval){
                mval=height[i];
                mindex=i;
            }
        }
        int tmpmax=0;
        int res=0;
        for(int i=0;i<mindex;++i){
            if(height[i]>tmpmax){
                tmpmax=height[i];
            }
            else{
                res+=tmpmax-height[i];
            }
        }
        tmpmax=0;
        for(int j=height.size()-1;j>mindex;--j){
            if(height[j]>tmpmax){
                tmpmax=height[j];
            }
            else{
                res+=tmpmax-height[j];
            }
        }
        return res;
    }
};
