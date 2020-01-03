/*
 * @Author: haha_giraffe
 * @Date: 2019-12-31 22:14:28
 * @Description: LRU
 */

/* 
    解题思路：这道题记住：map + list就行
*/
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = find(l.begin(), l.end(), key);
        if (it == l.end()){
            return -1;
        }
        l.erase(it);
        l.push_front(key);
        return m[key];
    }
    
    void put(int key, int value) {
        auto it = find(l.begin(), l.end(), key);
        if(it == l.end()){
            if(l.size() == cap){
                int tmp = l.back();
                l.pop_back();
                m.erase(tmp);
            }
            l.push_front(key);
        }
        else{
            l.erase(it);
            l.push_front(key);
        }
        m[key] = value;
    }
private:
    map<int, int> m;
    list<int> l;
    int cap;
};
