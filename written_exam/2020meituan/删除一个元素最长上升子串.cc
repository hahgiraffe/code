/*
 * @Author: haha_giraffe
 * @Date: 2020-03-19 20:00:36
 * @Description: 删除一个元素最长上升子串
 */
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void func1(){
    int num = 0;
    cin >> num;
    vector<int> vec;
    for(int i = 0; i < num ; ++i){
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    int res = 0;
    for(int i = 0; i < num; ++i){
        int tmp = 1;
        bool gone = false;
        int last = vec[i];
        for(int j = i+1; j < num; ++j){
            if(vec[j] > last){
                tmp++;
                last = vec[j];
            } else {
                if(gone == false){
                    gone = true;
                    continue;
                } else {
                    break;
                }
            }
        }
        res = max(res, tmp);
    }
    cout << res << endl;
}

/* 
    还可以用dp来解决
*/
void func2(){
    int n;
    cin >> n;
    vector<int> vec;
    for(int i = 0; i < n; ++i){
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    int dp1[n];
    int dp2[n];
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    dp1[0] = 1;
    for(int i = 1; i < n; ++i){
        if(vec[i] > vec[i-1]){
            dp1[i] = dp1[i-1] + 1;
        } else {
            dp1[i] = 1;
        }
    }
    dp2[n-1] = 1;
    for(int i = n-2; i >=0; --i){
        if(vec[i] < vec[i+1]){
            dp2[i] = dp2[i+1] + 1;
        } else {
            dp2[i] = 1;
        }
    }
    int res = 0;
    for(int i = 0; i < n; ++i){
        res = max(res, dp1[i]);
    }
    for(int i = 1; i < n-1; ++i){
        if(vec[i-1] < vec[i+1]){
            res = max(res, dp1[i-1] + dp2[i+1]);
        }
    }
    cout << res << endl;
}

int main(){
    // func1();
    func2();
    return 0;
}