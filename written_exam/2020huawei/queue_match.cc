/*
 * @Author: haha_giraffe
 * @Date: 2020-08-19 09:27:00
 * @Description: 
 * 某个打印机根据打印机队列执行打印任务，打印任务分为九个优先级，分别用数字1~9表示，数字越大优先级越高。
 * 打印机每次从队列头部取出第一个任务A，然后检查队列余下任务中有没有比A优先级更高的任务，则将任务A放在队列尾部，否则就执行任务A的打印。
 * 请编写一个程序，根据输入的打印队列，编出实际的打印顺序。
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> input;
        deque<pair<int, int>> dp;
        for(int i = 0; i < n; ++i){
            int tmp = 0;
            cin >> tmp;
            input.push_back(tmp);
            dp.push_back({tmp, i});
        }

        while(!dp.empty()){
            auto t = dp.front();
            dp.pop_front();
            int tmpValue = t.first;
            bool flag = true;
            for(auto it = dp.begin(); it != dp.end(); ++it){
                if(it->first > tmpValue){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout << t.second << " ";
            } else {
                dp.push_back(t);
            }
        }
    }

}