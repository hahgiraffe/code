/*
 * @Author: haha_giraffe
 * @Date: 2020-03-06 11:39:52
 * @Description: 
 */
#include <queue>
#include <iostream>

// void heapsort(std::vector<int>& vec){
//     std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
//     for(auto a : vec){
//         pq.push(a);
//     }
//     std::vector<int> res;
//     while(!pq.empty()){
//         int tmp = pq.top();
//         pq.pop();
//         res.push_back(tmp);
//     }
//     vec.swap(res);
// }

#define left(index) ((index) * 2 + 1)
#define right(index) ((index) * 2 + 2)

void swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

void adjustheap(std::vector<int>& vec, int i , int len){
    int index = i;
    int value = vec[i];
    if(left(i) < len){
        if(vec[left(i)] > vec[index]){
            index = left(i);
            value = vec[left(i)];
        }
    }

    if(right(i) < len){
        if(vec[right(i)] > vec[index]){
            index = right(i);
            value = vec[right(i)];
        }
    }

    if(value != vec[i]){
        swap(vec[i], vec[index]);
        adjustheap(vec, index, len);
    }
}


void heapsort(std::vector<int>& vec){
    for(int i = vec.size() / 2 - 1; i >= 0; --i){
        adjustheap(vec, i, vec.size());
    }

    for(int i = vec.size() - 1; i >= 0; --i){
        swap(vec[0], vec[i]);
        adjustheap(vec, 0, i);
    }
}

int main(){
    // std::vector<int> vec{2,4,6,1,56,1,6};
    std::vector<int> vec{38,55,65,97,27,76};
    heapsort(vec);
    for(auto a : vec){
        std::cout << a << " ";
    }
    std::cout << std::endl;
    return 0;
}