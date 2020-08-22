/*
 * @Author: haha_giraffe
 * @Date: 2020-08-16 19:37:53
 * @Description: 单例模式实现
 */


//懒汉模式，只有在需要调度函数的时候才初始化
class Singleton{
public:
    static Singleton& getInstance(){
        static Singleton instance;
        return instance;
    }

private:
    Singleton(){}
    ~Singleton(){}
    Singleton(const Singleton&) = delete;
    const Singleton& operator = (const Singleton&) = delete;
};


//饿汉模式，程序一开始运行就初始化了
class Singleton{
public:
    Singleton* getInstance(){
        return ptr;
    }
    void deleteInstance(){
        if(ptr){
            delete ptr;
            ptr = nullptr;
        }
    }
private:
    static Singleton* ptr;
    Singleton(){}
    ~Singleton(){}
    Singleton(const Singleton&) = delete;
    const Singleton& operator = (const Singleton&) = delete;
};

Singleton* Singleton::ptr = new Singleton;