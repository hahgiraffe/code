/*
 * @Author: haha_giraffe
 * @Date: 2020-01-16 16:05:24
 * @Description: LFU实现
 *  设计并实现最不经常使用（LFU）缓存的数据结构。它应该支持以下操作：get 和 put。
    get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
    put(key, value) - 如果键不存在，请设置或插入值。
    当缓存达到其容量时，它应该在插入新项目之前，使最不经常使用的项目无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，最近最少使用的键将被去除。
 */

/* 
    解题思路：这道题目非常经典，首先要知道LFU与LRU的区别，LFU是把最少访问的数据删除（包括读和写），如果如果删除的时候使用频率相同，则按照最近最少使用的规则
    LRU的重点在于list + map的结构，LFU也是一样重点在于数据结构，三个map + minF，代码和思路都是最清楚的
    第一个map存储key + pair<value, frequency>
    第二个map存储frequency + list<key>
    第三个map存储key + list::iterator
    在写思路的时候注意细节就好
*/
class LFUCache {
public:
    LFUCache(int capacity) {
        m_cap = capacity;
        m_size = 0;
        m_minF = 1;
    }
    
    int get(int key) {
        //if not find then return -1
        if(k_vf.find(key) == k_vf.end()) return -1;
        //if found then change freq
        int freq = k_vf[key].second;
        f_list[freq].erase(k_iter[key]);
        k_vf[key].second++;                              //get也要+1
        f_list[freq+1].push_back(key);
        k_iter[key] = --f_list[freq+1].end();   //这里不能用back()因为其返回最后一个值，这里要一个iterator，且iterator没有-1，只有--
        
        //
        if(f_list[m_minF].empty()){
            m_minF++;
        }
        return k_vf[key].first;
    }
    
    void put(int key, int value) {
        if(m_cap == 0) return;  //有一个用例cap = 0
        //if found
        if(get(key) != -1){
            k_vf[key].first = value;
            return;
        }
        // size == capacity need erase one
        if(m_size == m_cap){
            auto tmp = f_list[m_minF].front();
            k_vf.erase(tmp);
            k_iter.erase(tmp);
            f_list[m_minF].pop_front();
            --m_size;
        }
        // insert a new one 
        k_vf[key] = make_pair(value, 1);
        f_list[1].push_back(key);
        k_iter[key] = --f_list[1].end();
        m_minF = 1;
        ++m_size;
        return;
    }
private:
    int m_cap;                                      //capacity
    int m_size;                                     //size
    int m_minF;                                     //most small freq
    unordered_map<int, pair<int, int>> k_vf;        //key to pair<value, freq>
    unordered_map<int, list<int>> f_list;           //freq to list<key>
    unordered_map<int, list<int>::iterator> k_iter; //key to iterator
};