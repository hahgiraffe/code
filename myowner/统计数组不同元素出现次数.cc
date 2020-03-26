/*
 * @Author: haha_giraffe
 * @Date: 2020-03-17 20:42:54
 * @Description: 
一个长度大小为n的数组，数组中的每个元素的取值范围在[1,n]，且为正整数。
问：如何在时间复杂度为O(n)，空间复杂度为O(1)的条件下，统计数组中不同元素出现的次数。
 */

/* 
    解题思路:因为按照要去,只能在数组中,原地更迭.
*/
#include <vector>
#include <iostream>
using namespace std;


void match(vector<int>& vec){
    int n = vec.size();
    int i = 0;
    while(i < n){
        int tmp = vec[i] - 1;
        if(tmp < 0){
            i++;
            continue;
        }
        if(vec[tmp] > 0){
            vec[i] = vec[tmp];
            vec[tmp] = -1;
        } else {
            vec[tmp]--;
            vec[i] = 0;
        }
    }
    return;
}

int main(){
    vector<int> vec{3,4,2,1,4};
    match(vec);
    for(int i = 0; i < vec.size(); ++i){
        cout << i+1 << " : " << -vec[i] << endl;
    }
    cout << endl;
    return 0;
}