/*
 * @Author: haha_giraffe
 * @Date: 2020-03-06 10:38:44
 * @Description: 冒泡排序
 */
#include <vector>
#include <iostream>
void swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}
void bubblesort(std::vector<int>& vec){
    int n = vec.size();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n - i -1; ++j){
            if(vec[j] > vec[j + 1]){
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main(){
    // std::vector<int> vec{2,4,6,1,56,1,6};
    std::vector<int> vec{38,55,65,97,27,76};
    bubblesort(vec);
    for(auto a : vec){
        std::cout << a << " ";
    }
    std::cout << std::endl;
    return 0;
}