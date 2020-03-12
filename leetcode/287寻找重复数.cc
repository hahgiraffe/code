/*
 * @Author: haha_giraffe
 * @Date: 2020-01-16 21:37:59
 * @Description: 寻找重复数
 * 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。
 * 假设只有一个重复的整数，找出这个重复的数。
 * 不能更改原数组（假设数组是只读的）。
 * 只能使用额外的 O(1) 的空间。
 * 时间复杂度小于 O(n2) 。
 * 数组中只有一个重复的数字，但它可能不止重复出现一次。
 */
/* 
    解题思路：首先要把这道题目和剑指offer的第三题区别开，那题目的数字都在0-n-1的范围有多个重复数字，每个数字可重复多次，并且可以改变数组，可以用桶思想，交换即可。
    本题要求不能改变原数组，且只有一个重复的数字，但可以重复多次。
    这题很经典，一开始最容易想到排序（时间Ologn）和用set存储（空间On）都不太好
    可以用二分来做，不是在index上二分，而是在值域上二分。比如数组大小为5则范围在1-4，可以直接二分找中点，然后遍历数组查找比中点小的数个数，以此继续二分
    二分法的时间复杂度是O(nlogn)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + (r - l)/2;
            int count = 0;
            for(auto a : nums){
                if(a <= mid){
                    count++;
                }
            }
            if(count <= mid){
                l = mid + 1;
            }
            else{
                r =  mid;
            }
        }
        return l;
    }
};
/* 
    这道题目最好的方法其实是链表中有环，找环入口问题。时间复杂度为O(n)。整体思路如下：
    把数组当成链表，数组中的值指向下一个index的节点，因为数组中有重复的节点，所以形成的链表肯定有环（无论数组是否有序），
    然后就按照思路实现即可，先快慢指针，等两个指针相遇，再新建一个链表头指针，和慢指针一起走，两个指针相遇时候的index就是重复的节点
    同时也需要证明链表找环入口问题的证明
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0, f = 0;
        s = nums[s];
        f = nums[nums[f]];
        while(s != f){
            s = nums[s];
            f = nums[nums[f]];
        }
        int tmp = 0;
        while(tmp != s){
            s = nums[s];
            tmp = nums[tmp];
        }
        return tmp;
    }
};