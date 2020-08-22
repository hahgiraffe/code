#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int get(int a, int b){
    int tmp1 = 1;
    for(int i = 1; i <= b;++i){
        tmp1 *= i;
    }
    int tmp2 = 1;
    while(b--){
        tmp2 *= a;
        a--;
    }
    return tmp2 / tmp1;
}
int main(){
    int n;
    while(cin >> n){
        vector<int> vec;
        for(int i = 0; i < n; ++i){
            int tmp;
            cin >> tmp;
            vec.push_back(tmp);
        }
        map<int, int> m;
        for(auto a : vec){
            m[a]++;
        }
        if(m[0] == 0) return 0;
        long long res = 1;
        for(auto it = m.begin(); it != m.end(); ++it){
            int a = it->first;
            int b = it->second;
            if(a == 0) continue;
            int tmp = m[a-1] * 2;
            if(b == tmp) continue;
            int tmpres = get(tmp, b);
            res = (res * tmpres) % MOD;
        }
        cout << res << endl;
    }
}