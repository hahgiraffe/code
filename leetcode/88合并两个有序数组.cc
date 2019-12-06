/*
 * @Author: haha_giraffe
 * @Date: 2019-12-06 22:20:27
 * @Description: 合并两个有序数组
 *  给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
    说明:
    初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
    你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 */

/* 
    解题思路：看似简单，其实还挺有意思的，首先我想到的方法是将数组2中元素全放到数组1后面，然后sort
            还有一种是双指针，指针都指向两个数组的末尾，然后谁大谁放到数组以中
*/


class Solution {
public:
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { 
    //     for(int k = m; n>0;n--,k++){
    //         nums1[k]=nums2[k-m];
    //     }
    //     sort(nums1.begin(),nums1.end());
    //     return;
    // }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { 
        int index2 = n-1, index1 = m-1;
        int tmp = m+n-1;
        while(tmp>=0){
            if(index1 < 0){
                nums1[tmp--] = nums2[index2--];
            }
            else if(index2 < 0){
                nums1[tmp--] = nums1[index1--];
            }
            else{
                if(nums1[index1] > nums2[index2]){
                    nums1[tmp--] = nums1[index1--];
                }
                else{
                    nums1[tmp--] = nums2[index2--];
                }         
            }
        }
        return;
    }

};

