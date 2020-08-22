/*
 * @Author: haha_giraffe
 * @Date: 2020-08-19 09:14:52
 * @Description: 
 * 题目描述：给出一个不多于5位的整数，进行反序处理，要求

（1）求出它是几位数

（2）分别输出每一个数字（空格隔开）

（3）按逆序输出各位数字（仅数字间以空格间隔，负号与数字之间不需要间隔）

输入描述：位数不大于5的整数

输出描述：1.整数位数 2.空格间隔输出结果 3.逆序整数
 */
#include <bits/stdc++.h>
using namespace std;


int main(){
    int num;
    while(cin >> num){
        vector<int> vec;
        bool flag = false;
        if(num < 0) {
            flag = true;
            num = -num;
        }
        int tmp = num;
        while(tmp){
            int k = tmp % 10;
            tmp /= 10;
            vec.push_back(k);
        }

        cout << vec.size() << endl;
        for(int i = vec.size()-1; i >= 0; --i){
            if(i != 0){
                cout << vec[i] << " ";
            } else {
                cout << vec[i] << endl;
            }
        }

        int res = 0;
        for(auto a : vec){
            res = res * 10 + a;
        }
        if(flag)
            cout << -res << endl;
        else
            cout << res << endl;
    }
}