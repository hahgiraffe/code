/*
 * @Author: haha_giraffe
 * @Date: 2019-11-25 15:06:29
 * @Description: 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：(1)左括号必须用相同类型的右括号闭合。(2)左括号必须以正确的顺序闭合。(3)注意空字符串可被认为是有效字符串。
 */

/*  
    解题思路：直接上stack，三种类型左括号push，右括号则pop（注意pop之前要判断栈是否为空）
*/
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()){
            return true;
        }
        stack<char> sta;
        int n=s.size();
        bool res = true;
        for(int i=0;i<n;++i){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                sta.push(s[i]);
            }
            else{
                if(sta.empty()){
                    return false;
                }
                char tmp = sta.top();
                sta.pop();
                if(s[i]==')' && tmp != '('){
                    res = false;
                    break;
                }
                else if(s[i]==']' && tmp != '['){
                    res = false;
                    break;
                }
                else if(s[i]=='}' && tmp != '{'){
                    res = false;
                    break;
                }
            }
        }
        if(!sta.empty()){
            return false;
        }
        return res;
    }
};