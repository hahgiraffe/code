#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    while(cin >> n){
        cin >> m;
        vector<set<int>> vec;
        for(int i = 0; i < m; ++i){
           int a, b;
           cin >> a >> b;
            bool flag = false;
            for(auto& tmp : vec){
                auto res1 = tmp.find(a);
                auto res2 = tmp.find(b);
                if(res1 != tmp.end() && res2 != tmp.end()){
                    flag = true;
                    break;
                } else if (res1 != tmp.end() && res2 == tmp.end()){
                    flag = true;
                    tmp.insert(b);
                    break;
                } else if(res1 == tmp.end() && res2 != tmp.end()){
                    flag = true;
                    tmp.insert(a);
                    break;
                } else {
                    continue;
                }
            }
            if(!flag){
                set<int> s;
                s.insert(a);
                if(a != b) s.insert(b);
                vec.push_back(s);
            }
        }
        
        cout << vec.size() << endl;
        for(auto a : vec){
            for(auto itr = a.begin(); itr != a.end(); ++itr){
                if(itr == a.begin()){
                    cout << *itr;
                } else {
                    cout << " " << *itr;
                }
            }
            cout << endl;
        }
    }
    return 0;
}