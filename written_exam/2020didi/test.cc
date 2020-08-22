/*
 * @Author: haha_giraffe
 * @Date: 2020-08-21 19:35:56
 * @Description: 
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<pair<int, int>> vec;
        for(int a = 1; a <= 9; ++a){
            for(int b = 0; b <= 9; ++b){
                for(int c = 0; c <= 9; ++c){
                    if(a == b || a == c || b == c) continue;
                    int tmpa = a * 100 + b * 10 + c;
                    int tmpb = a * 100 + c * 10 + c;
                    if(tmpa + tmpb == n){
                        vec.push_back({tmpa, tmpb});
                    } 
                }
            }
        }

        cout << vec.size() << endl;
        for(auto a:vec){
            cout << a.first << " " << a.second << endl;
        }
    }
}