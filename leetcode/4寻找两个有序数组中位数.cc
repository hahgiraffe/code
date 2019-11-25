/*
 * @Author: haha_giraffe
 * @Date: 2019-11-23 23:53:15
 * @Description: 寻找两个有序数组的中位数
 */

/* 
    解法1：最容易想到的就是将两个数组合二为一，然后找中位数就ok了
    解法2：中位数分割（具体详见算法导论）

*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        int i=0,j=0;
        vector<double> v;
        while(i!=len1 && j!=len2)
        {
            if(nums1[i]>nums2[j])
            {
                v.push_back(nums2[j]);
                j++;
            }
            else
            {
                v.push_back(nums1[i]);
                i++;
            }
        }
        if(i!=len1)
        {
            while(i!=len1)
            {
                v.push_back(nums1[i]);
                i++;
            }
        }
        else
        {
            while(j!=len2)
            {
                v.push_back(nums2[j]);
                j++;
            }
        }
        if((len1+len2)%2==0)
        {
            return (v[(len1+len2)/2-1]+v[(len1+len2)/2])/2;
        }
        else
        {
            return v[(len1+len2)/2];
        }
        
    }
};