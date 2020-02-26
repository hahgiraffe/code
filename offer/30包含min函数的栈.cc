/*
 * @Author: haha_giraffe
 * @Date: 2020-02-26 23:53:19
 * @Description: 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
 */

/* 
    解题思路：两个栈实现
*/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(mins.empty()){
            mins.push(x);
            return ;
        }
        if(x > mins.top()){
            int t = mins.top();
            mins.push(t);
        }
        else{
            mins.push(x);
        }
    }
    
    void pop() {
        s.pop();
        mins.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return mins.top();
    }
private:
    stack<int> s;
    stack<int> mins;
}; 