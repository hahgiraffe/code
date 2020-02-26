/*
 * @Author: haha_giraffe
 * @Date: 2020-02-27 00:19:48
 * @Description: 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
 */
/* 
    解题思路：用一个栈模拟，压入和弹出过程，主要是当栈顶元素等于弹出序列的时候，才弹出，否则一直压入
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> s;
        int j = 0;
        for(int i = 0; i < n; ++i){
            s.push(pushed[i]);
            while(!s.empty() && j < n && s.top() == popped[j]){
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};