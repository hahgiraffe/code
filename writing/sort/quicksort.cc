/*
 * @Author: haha_giraffe
 * @Date: 2020-03-06 09:42:25
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <stack>

/* 
    有两种优化手法，一种是三值取中，还有一种是当数组较小的时候用insert sort替代
*/
void swap(int& a , int& b){
    int tmp = a;
    a = b;
    b = a;
}
int partition(std::vector<int>& vec, int l , int r){
    // int mid = left + (right - left)/2;
    // if((vec[left] <= vec[mid] && vec[left] >= vec[right]) || (vec[left] <= vec[right] && vec[left] >= vec[mid])){
    //     // swap(vec[left], vec[left];
    // }
    // else if((vec[mid] <= vec[left] && vec[mid] >= vec[right]) || (vec[mid] <= vec[right] && vec[mid] >= vec[left])){
    //     swap(vec[left], vec[mid]);
    // }
    // else if((vec[right] <= vec[mid] && vec[left] <= vec[right]) || (vec[right] <= vec[left] && vec[right] >= vec[mid])){
    //     swap(vec[left], vec[right]);
    // }
    int tmp = vec[l];
    while(l < r){
        while(l < r && vec[r] >= tmp) r--;
        vec[l] = vec[r];
        // swap(vec[l], vec[r]);
        while(l < r && vec[l] <= tmp) l++;
        vec[r] = vec[l];
        // swap(vec[l], vec[r]);
    }
    vec[l] = tmp;
    return l;
}

void mysort(std::vector<int>& vec, int l , int r){
    if(l >= r){
        return;
    }
    int target = partition(vec, l ,r);
    mysort(vec, l, target - 1);
    mysort(vec, target + 1, r);
}

void quicksort(std::vector<int>& vec){
    mysort(vec, 0, vec.size() - 1);
}


void mysort2(std::vector<int>& vec, int left, int right){
    std::stack<int> s;
    s.push(left);
    s.push(right); 
    while(!s.empty()){
        int r = s.top();s.pop();
        int l = s.top();s.pop();
        if(l < r){
            int k = partition(vec, l, r);
            if(k > l){
                s.push(l);
                s.push(k-1);
            }
            if(k < r){
                s.push(k+1);
                s.push(r);
            }
        }
    }
    
}

//非递归quicksort
void quicksort_2(std::vector<int>& vec){
    mysort2(vec, 0, vec.size()-1);
}

int main(){
    std::vector<int> vec{2,4,6,1,56,1,6};
    quicksort_2(vec);
    for(auto a : vec){
        std::cout << a << " ";
    }
    std::cout << std::endl;
    return 0;
}