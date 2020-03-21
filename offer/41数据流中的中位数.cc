/*
 * @Author: haha_giraffe
 * @Date: 2020-03-13 08:21:59
 * @Description: 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值.
 * 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
 */
/* 
    解题思路：用两个堆，大根堆记录中位数左边的，小根堆记录中位数右边的，插入的时候进行调换
*/
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        pq1.push(num);
        pq2.push(pq1.top());
        pq1.pop();
        if(pq1.size() < pq2.size()){
            pq1.push(pq2.top());
            pq2.pop();
        }
    }
    
    double findMedian() {
        return pq1.size() > pq2.size() ? pq1.top() : (pq2.top() + pq1.top()) * 0.5;
    }
private:
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
};