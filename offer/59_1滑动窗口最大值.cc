/*
 * @Author: haha_giraffe
 * @Date: 2020-03-17 21:30:22
 * @Description: 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
 */
/* 
    解题思路:用一个deque从大到小,存储数据所在的index,一开始先把k-1个数放进去,如果插入的值大于deque.back()则pop_back
            然后正式放入的时候,要首先考虑当前最大值,是否在窗口内,即deque.front() < i - k + 1 则deque.pop_front(),然后正常的后面插入
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        int n = nums.size();
        if(n < 1 || k < 1) return res;
        for(int i = 0; i < k - 1; ++i){
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(int i = k-1; i < n; ++i){
            if(!dq.empty() && dq.front() < i - k + 1){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};