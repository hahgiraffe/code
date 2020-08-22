/*
 * @Author: haha_giraffe
 * @Date: 2020-08-17 09:35:13
 * @Description: 
 */
#include <thread>
#include <condition_variable>
#include <iostream>

std::mutex mu;
std::condition_variable cv;
bool flag = true;

void func1(){
    while (1)
    {
        std::unique_lock<std::mutex> lck(mu);
        while(!flag){
            cv.wait(lck);
        }
        std::cout << "func1" << std::endl;
        flag = !flag;
        cv.notify_one();
    }
    
}

void func2(){
    while (1)
    {
        std::unique_lock<std::mutex> lck(mu);
        while(flag){
            cv.wait(lck);
        }
        std::cout << "func2" << std::endl;
        flag = !flag;
        cv.notify_one();
    }
}

int main(){
    std::thread t1(func1);
    std::thread t2(func2);
    t1.join();
    t2.join();
}