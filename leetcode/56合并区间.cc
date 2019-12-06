/*
 * @Author: haha_giraffe
 * @Date: 2019-12-03 22:48:43
 * @Description: 合并区间
 * 给出一个区间的集合，请合并所有重叠的区间。
 */

/* 
    解题思路：思路很简单，就是先排序，然后遍历每一个与下一个比较，看是否能合并
*/

class Solution {
public:
    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     sort(intervals.begin(), intervals.end(),[](vector<int> a, vector<int> b){
    //         if(a[0] < b[0])
    //             return true;
    //         else if(a[0] > b[0]){
    //             return false;
    //         }
    //         else{
    //             return a[1] < b[1] ? true : false;
    //         }
    //     });
    //     int n = intervals.size();
    //     int i=0;
    //     while(i < n){
    //         while(i+1 < n && intervals[i][1] >= intervals[i+1][0]){
    //             intervals[i][1] = max(intervals[i+1][1], intervals[i][1]);
    //             intervals.erase(intervals.begin() + i+1);
    //             n--;
    //         }
    //         i++;
    //     }
    //     return intervals;
    // }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.empty()){
            return res;
        }
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); ++i){
            if(res.back()[1] >= intervals[i][0] ){
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};