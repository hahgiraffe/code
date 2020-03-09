/*
 * @Author: haha_giraffe
 * @Date: 2020-03-08 10:10:26
 * @Description: 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
若队列为空，pop_front 和 max_value 需要返回 -1
*/

/* 
    解题思路：队列的最大值，需要一个deque来辅助，deque中的元素顺序是从大到小，push的时候要把deque中所有小于当前元素的元素都弹出，pop的时候判断第一个元素是否为当前pop的元素
*/
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(!d.empty()){
            return d.front();
        }
        return -1;
    }
    
    void push_back(int value) {
        q.push(value);
        while(!d.empty() && value > d.back()){
            d.pop_back();
        }
        d.push_back(value);
    }
    
    int pop_front() {
        if(q.empty()){
            return -1;
        }
        int tmp = q.front();
        q.pop();
        if(tmp == d.front()){
            d.pop_front();
        }
        return tmp;
    }
private:
    queue<int> q;
    deque<int> d;

};
