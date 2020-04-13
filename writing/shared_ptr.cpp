/*
 * @Author: haha_giraffe
 * @Date: 2020-03-16 10:12:03
 * @Description: 
 */
#include <iostream>
using namespace std;

template <typename T>
class Shared_ptr{
public:
    Shared_ptr(): m_ptr(NULL), count(new int(0)){ }
    explicit Shared_ptr(T* ptr): m_ptr(ptr), count(new int(1)) { }
    Shared_ptr(const Shared_ptr& sp): m_ptr(sp.m_ptr), count(sp.count){
        ++(*count);
    }
    Shared_ptr& operator =(Shared_ptr& rhs){
        if(this == &rhs){
            return *this;
        }
        // std::swap(*this, rhs);
        ++(*rhs.count);
        if(--*count == 0){
            delete count;
            delete m_ptr;
        }
        this->m_ptr = rhs.m_ptr;
        this->count = rhs.count;
        return *this;
    }
    ~Shared_ptr(){
        --(*count);
        if(*count == 0){
            delete m_ptr;
            delete count;
        }
        m_ptr = NULL;
        count = NULL;
    }
    void swap(Shared_ptr& sp){
        std::swap(m_ptr, sp.m_ptr);
        std::swap(count, sp.count);
    }
    int getrefcount() const {
        return *count;
    }
private:
    T* m_ptr;
    int* count;

};

int main(){
    Shared_ptr<int> ptr(new int(22));
    cout << ptr.getrefcount();
    Shared_ptr<int> ptr2(ptr);
    cout << ptr2.getrefcount();
    Shared_ptr<int> ptr3(new int(44));
    ptr3 = ptr;
}