/*
 * @Author: haha_giraffe
 * @Date: 2020-01-03 21:22:00
 * @Description: 第k个最大元素
 */

/* 
    最简单的方法就是用堆排序，可以用priority_queue优先队列代替，但是注意要greater<int>表示倒序从大到小
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i=0; i < n; ++i){
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};