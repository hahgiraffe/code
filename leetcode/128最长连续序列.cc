/*
 * @Author: haha_giraffe
 * @Date: 2020-08-12 21:18:39
 * @Description:给定一个未排序的整数数组，找出最长连续序列的长度。
要求算法的时间复杂度为 O(n)。 
 */
/* 
解题思路：用一个set存储数据，如果查找的节点左边为空，则开始在set中遍历右边的数是否存在
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(auto a : nums) s.insert(a);
        int res = 0;
        for(auto a : nums){
            if(s.find(a-1) == s.end()){
                int tmp = 1;
                int i = a+1;
                while(s.find(i) != s.end()){
                    i++;
                    tmp++;
                }
                res = max(res, tmp);
            }
        }
        return res;
    }
};