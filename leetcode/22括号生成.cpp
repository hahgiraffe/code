/*
 * @Author: haha_giraffe
 * @Date: 2019-11-01 20:04:33
 * @Description: 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 比如输入n=3
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 */

/*
    解题思路：这题目的思路就是dfs递归，第一种方法差点超时，难点在于想左右括号和递归返回的条件。
    重点看看第二种思路，其实主要看上面的样例可知，规律就是左括号和右括号都是n个，当左括号有剩余则加上左括号，否则加上右括号，这样就不需要判断是否有效（因为主要达到2×n必定是有效组合）
 */
class Solution {
public:
//     bool check(string tmp){
//         stack<char> sta;
//         for(int i=0;i<tmp.size();++i){
//             if(tmp[i]=='('){
//                 sta.push(tmp[i]);
//             }
//             else{
//                 if(sta.empty()){
//                     return false;
//                 }
//                 char t = sta.top();
//                 sta.pop();
//             }
//         }
//         if(!sta.empty()){
//             return false;
//         }
//         return true;
//     }
//     void dfs(int n ,int leftnow,int rightnow, string tmp,vector<string>& res){
//         if(leftnow<0 || rightnow<0){
//             return;
//         }
//         if(tmp.size() == n*2 && !leftnow && !rightnow){
//             if(check(tmp)) res.push_back(tmp);
//             return;
//         }
//         if(leftnow){
//             dfs(n,leftnow-1,rightnow,tmp+'(',res);
//         }
//         if(rightnow){
//             dfs(n,leftnow,rightnow-1,tmp+')',res);
//         }
        
//     }
//     vector<string> generateParenthesis(int n) {
//         string tmp;
//         vector<string> res;
//         if(!n){
//             return res;
//         }
//         dfs(n,n,n,tmp,res);
//         return res;
//     }
    void dfs(string tmp,vector<string>& res,int l,int r,int m){
        if(tmp.size() == m*2){
            res.push_back(tmp);
            return;
        }
        if(l<m){
            dfs(tmp+'(',res,l+1,r,m);
        }
        if(r<l){
            dfs(tmp+')',res,l,r+1,m);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string tmp;
        dfs(tmp,res,0,0,n);
        return res;
    }
};