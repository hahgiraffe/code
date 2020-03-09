/*
 * @Author: haha_giraffe
 * @Date: 2020-03-02 23:20:51
 * @Description: 给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
 */
/*
    解题思路：这道题目在不能用乘法的情况下，两边往中间遍历，时间复杂度和空间复杂度都是O(n)
*/
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> res(n, -1);
        
        int l = 1;
        for(int i = 0; i < n; ++i){
            res[i] = l;
            l *= a[i];
        }
        
        int r = 1;
        for(int i = n-1; i >=0; --i){
            res[i] *= r;
            r *= a[i];
        }
        return res;
    }
};