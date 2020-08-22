/*
 * @Author: haha_giraffe
 * @Date: 2020-08-21 19:47:30
 * @Description: 
 */
#include <bits/stdc++.h>
using namespace std;

vector<long long> getNumber(int n){
    long long a = 1;
    long long b = 1;
    vector<long long> vec;
    vec.push_back(1);
    vec.push_back(1);
    while(vec.size() < n){
        long long c = a + b;
        a = b;
        b = c;
        vec.push_back(c);
    }
    return vec;
}

int main(){
    int n;
    while(cin >> n){
        vector<long long> vec = getNumber(n*n);
        sort(vec.begin(), vec.end(), [](long long a, long long b){
            return a > b;
        });
        int u = 0, l = 0, d = n-1, r = n-1;
        vector<vector<long long>> arr(n, vector<long long>(n, 0));
        int len = 0;
        while(len < vec.size()){
            for(int i = l; i <= r; ++i){
                arr[u][i] = vec[len++];
            }
            ++u;
            if(u > d || len >= vec.size()) break;
            for(int j = u; j <= d; ++j){
                arr[j][r] = vec[len++];
            }
            --r;
            if(l > r || len >= vec.size()) break;
            for(int i = r; i >= l; --i){ 
                arr[d][i] = vec[len++];
            }
            --d;
            if(u > d || len >= vec.size()) break;
            for(int j = d; j >= u; --j){
                arr[j][l] = vec[len++];
            }
            ++l;
            if(l > r || len >= vec.size()) break;
        }
        for(int i = 0; i < arr.size(); ++i){
            for(int j = 0; j < arr[0].size(); ++j){
                if(j == 0){
                    cout << arr[i][j];
                } else {
                    cout << " " << arr[i][j];
                }
            }
            cout << endl;
        }
    }
}