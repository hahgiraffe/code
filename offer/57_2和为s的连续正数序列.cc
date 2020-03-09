/*
 * @Author: haha_giraffe
 * @Date: 2020-03-05 11:10:45
 * @Description: 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
 * 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
 */
/* 
    解题思路：快慢指针
*/
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int l = 0, r = 0;
        int tmpsum = 0;
        vector<vector<int>> res;
        while(r <= target / 2 + 1){
            if(tmpsum == target){
                vector<int> tmp;
                for(int i = l+1; i <= r; ++i){
                    tmp.push_back(i);
                }
                if(tmp.size() >= 2){ 
                    res.push_back(tmp);
                }
                r++;
                tmpsum += r;
            }
            while(tmpsum < target && r <= target/2 +1){
                r++;
                tmpsum += r;
            }
            while(tmpsum > target ){
                l++;
                tmpsum -= l;
            }
        }
        return res;
    }
};