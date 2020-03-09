/*
 * @Author: haha_giraffe
 * @Date: 2020-03-06 10:24:19
 * @Description: 
 */
#include <vector>
#include <iostream>
/* 
    插入排序思路就是每个元素插入之前排序好的序列，所以内层遍历需要从后往前
*/

void insertsort(std::vector<int>& vec){
    int n = vec.size();
    for(int i = 1; i < n; ++i){
        int tmp = vec[i];
        int j = i -1;
        for( ; j >= 0; --j){
            if(vec[j] > tmp){
                vec[j+1] = vec[j];
                if(j == 0) vec[0] = tmp;
            } else {
                vec[j+1] = tmp;
                break;
            }
        }
        // if(j == 0) vec[0] = tmp;
    }
}

int main(){
    // std::vector<int> vec{2,4,6,1,56,1,6};
    std::vector<int> vec{38,55,65,97,27,76};
    insertsort(vec);
    for(auto a : vec){
        std::cout << a << " ";
    }
    std::cout << std::endl;
    return 0;
}