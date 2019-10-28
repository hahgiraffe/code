/*
 * @Author: haha_giraffe
 * @Date: 2019-10-28 20:33:39
 * @Description: 串联字符串的最大长度
 * 给定一个字符串数组 arr，字符串 s 是将 arr 某一子序列字符串连接所得的字符串，如果 s 中的每一个字符都只出现过一次，那么它就是一个可行解。请返回所有可行解 s 中最长长度。
 * 输入：arr = ["un","iq","ue"]
 * 输出：4
 * 解释：所有可能的串联组合是 "","un","iq","ue","uniq" 和 "ique"，最大长度为 4。
 */

/* 这个题目因为数据量比较小（arr.size() <= 16），可以直接dfs，arr中的每一个元素分为取 or 不取 
   这里还有一个小技巧，就是判断一个字符串数组中任选几个构成一个字符串，保证这个字符串中的每个字符只有一个，可以用一个vector<int> arr(26,0)保持每个字符（a-z）的个数
   如果有>1则不满足条件 
*/

class Solution {
public:
    void dfs(vector<string> arr,int now,int& res,string str,vector<int>& num){
        if(res < str.size()){
            res = str.size();
        }
        if(now >= arr.size()){
            return;
        }
        //这个dfs是没有选择的
        dfs(arr,now+1,res,str,num);
        
        //choose
        for(int i=0;i<arr[now].size();++i){
            num[arr[now][i]-'a']++;
        }
        int flag = true;
        for(int i=0;i<num.size();++i){
            if(num[i]>1){
                flag =false;
                break;
            }
        }
        if (flag) {
            dfs(arr,now+1,res,str+arr[now],num);
        }
        for(int i=0;i<arr[now].size();++i){
            num[arr[now][i]-'a']--;
        }
    }
    int maxLength(vector<string>& arr) {
        //2^26很小可以直接dfs，每个元素选or不选
        vector<int> num(30,0);
        int res = 0;
        dfs(arr,0,res,"",num);
        return res;
    }
};