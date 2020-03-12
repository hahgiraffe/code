/*
 * @Author: haha_giraffe
 * @Date: 2020-03-06 11:39:52
 * @Description: 
 */

/* 
    堆排序，重点
*/
#include <vector>
#include <iostream>

using namespace std;

#define left(l) (2 * (l) + 1)
#define right(r) (2 * (r) + 2)

void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

void heap_adjust(std::vector<int>& vec, int index, int len){
    int idx = index;
    int val = vec[index];

    if(left(index) < len){
        if(vec[left(index)] > val){
            idx = left(index);
            val = vec[left(index)];
        }
    }

    if(right(index) < len){
        if(vec[right(index)] > val){
            idx = right(index);
            val = vec[right(index)];
        }
    }

    if(val != vec[index]){
        swap(vec[index], vec[idx]);
        heap_adjust(vec, idx, len);
    }
}

void heap_sort(std::vector<int>& vec){
    //建立堆
    int n = vec.size();
    for(int i = n / 2 -1; i >= 0; --i){
        heap_adjust(vec, i, n);
    }

    //调整堆
    int tmp = n-1;
    while(tmp > 0){
        swap(vec[tmp], vec[0]);
        heap_adjust(vec, 0, tmp);
        tmp--;
    }

}

int main(){
    std::vector<int> vec{2,4,6,44,2,1,55,6,7,43,2,1,45,6,3246};
    heap_sort(vec);

    for(auto a : vec){
        cout << a << " ";
    }
    // cout <<"sdasda";
    cout << endl;
}