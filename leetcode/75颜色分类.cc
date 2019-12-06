/*
 * @Author: haha_giraffe
 * @Date: 2019-12-05 23:13:17
 * @Description: 颜色分类
 *  给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
    此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 */

/* 
    这道题目很经典，一开始想到的方法就是遍历两次（一次从前往后找0，一次从后往前找2，如果找到则与对应的交换）
    还有一个更好的只有遍历一次，遍历一遍一边找0，一边找2，可以看成三个指针，但是注意如果是从前往后遍历，找到0的时候交换当前指针要+1(因为前面的都扫描过了)，当找2的时候当前指针不用--
*/

class Solution {
public:
    // void sortColors(vector<int>& nums) {
    //     int n=nums.size();
    //     int index0=0;
    //     int index2=n-1;
    //     for(int i=0;i<nums.size();++i){
    //         if(nums[i]==0){
    //             swap(nums[i],nums[index0++]);
    //         }
    //     }
    //     for(int j=nums.size()-1;j>=0;--j){
    //         if(nums[j]==2){
    //             swap(nums[j],nums[index2--]);
    //         }
    //     }
    //     return ;
    // }
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int index0=0;
        int index2=n-1;
        int i = 0;
        while(i<=index2){
            if(nums[i]==0){
                swap(nums[i++],nums[index0++]);
            }
            else if(nums[i]==2){
                swap(nums[i], nums[index2--]);
            }
            else{
                i++;
            }
        }
        return ;
    }
};