/*
 * @Author: haha_giraffe
 * @Date: 2020-08-16 19:54:32
 * @Description: 
 */

template<typename T>
class Shared_ptr{
public:
    Shared_ptr() : ptr(nullptr), count(new int(0)) {}
    explicit Shared_ptr(T* rawPtr) :ptr(rawPtr), count(new int(1)){}
    ~Shared_ptr(){
        if(*count != 1){
            (*count)--;
        } else {
            delete count;
            delete ptr;
        }
        count = nullptr;
        ptr = nullptr;
    }

    Shared_ptr(const Shared_ptr& rawPtr)
        :ptr(rawPtr.ptr), count(rawPtr.count)
    {
        (*count)++;
    }

    const Shared_ptr& operator = (const Shared_ptr& sptr){
        if(&sptr == this){
            return *this;
        }
        if(*count == 1){
            delete count;
            delete ptr;
        } else {
            (*count)--;
        }
        this->ptr = sptr->ptr;
        this->count = sptr->count;
        (*this->count)++;
    }

    int getCount() const{
        return *count;
    }
private:
    T* ptr;
    int* count;

};