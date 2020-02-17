/*
 * @Author: haha_giraffe
 * @Date: 2020-02-16 00:04:42
 * @Description: 用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，
 * 分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
 */
/* 
    解题思路：主要注意首先要把第二个栈清空，如果没有的话再从第一个栈中取出来
*/
class CQueue {
public:
    CQueue() {
        // f.clear();
        // s.clear();
    }
    
    void appendTail(int value) {
        f.push(value);
    }
    
    int deleteHead() {
        if(!s.empty()){
            int tmp = s.top();
            s.pop();
            return tmp;
        }
        while(!f.empty()){
            int tmp = f.top();
            f.pop();
            s.push(tmp);
        }
        if(s.empty()){
            return -1;
        }
        else{
            int tmp = s.top();
            s.pop();
            return tmp;
        }
    }
private:
    stack<int> f;
    stack<int> s;
};