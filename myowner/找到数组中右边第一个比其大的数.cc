/*
 * @Author: haha_giraffe
 * @Date: 2020-03-18 10:44:21
 * @Description: 找出数组中,右边第一个比其大的数
 */
/* 
    解题思路:正常O(n^2)的解法很简单,如果想要O(n)就要用一个单调栈来辅助,栈中存储的是index,
    首先把一个0放入栈中,然后遍历元素,与栈顶元素所在值进行比较,如果大于则新插入的值就是栈顶元素右边第一个大于其的数.如果小于,则直接放入栈中即可
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> myfind(vector<int> vec){
    int n = vec.size();
    vector<int> res (n, -1);
    stack<int> s;
    s.push(0);
    for(int i = 1; i < n; ++i){
        while(!s.empty() && vec[i] > vec[s.top()]){
            res[s.top()] = vec[i];
            s.pop();
        }
        s.push(i);
    }
    return res;
}

int gen(int m,int n)
{
    int i, select = m,remaining = n;
    for(i=0;i<n;i++) {
        if(rand() % remaining <select) {
            // printf("%d\n",i);
            cout << i << endl;
            select--;
        }
        remaining--;
    }
    return 0;
}

int main(){
    // vector<int> vec{3,5,1,4,6};
    // auto res = myfind(vec);    
    // for(auto a : res){
    //     cout << a << " ";
    // }
    // cout << endl;
    gen(2, 5);
    return 0;
}
