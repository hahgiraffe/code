/*
 * @Author: haha_giraffe
 * @Date: 2020-02-15 17:40:47
 * @Description: 懒汉模式和饿汉模式的单例模式，保证线程安全
 */

/* 
    懒汉模式，Meyes Singleton 直到使用的时候才初始化。注意要到c++11后才能保证局部静态变量线程安全

*/
class Singleton{
private:
    Singleton(){ }
    ~Singleton(){ }
    Singleton(const Singleton&) = delete;
    const Singleton& operator = (const Singleton&) = delete;
public:
    static Singleton& GeInstance(){
        static Singleton single;
        return single;
    }
};

/* 
    饿汉模式，程序一开始就初始化单例
*/


class Singlenton_2{
private:
    Singlenton_2(){ }
    ~Singlenton_2(){ }
    Singlenton_2(const Singlenton_2&) = delete;
    const Singlenton_2& operator = (const Singlenton_2&) = delete;
    static Singlenton_2* single;

public:
    static Singlenton_2* GetInstance(){
        return single;
    }
    static void DeleteInstance(){
        if(single){
            delete single;
            single = nullptr;
        }
    }
};
//全局初始化
Singlenton_2* Singlenton_2::single = new Singlenton_2;

/* 
    模板+pthread_once（陈硕推荐版本），pthread_once保证只执行一次，但是没有销毁对象，static对象也只有一个
*/
#include <pthread.h>

template<typename T>  
class Singleton_3
{
public:
    static T& instance()
    {
        pthread_once(&ponce_, &Singleton::init);
        return *value_;
    }

    static void init()
    {
        value_ = new T();
    }
private:
    Singleton_3(){}
    ~Singleton_3(){}
    const Singleton_3& operator = (const Singleton_3&) = delete;
    Singleton_3(const Singleton_3&) = delete;
    static pthread_once_t ponce_;
    static T* value_;
};
template<typename T>  
pthread_once_t Singleton_3<T>::ponce_ = PTHREAD_ONCE_INIT;

template<typename T>  
T* Singleton_3<T>::value_ = NULL; 