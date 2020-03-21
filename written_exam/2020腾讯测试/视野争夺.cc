/*
 * @Author: haha_giraffe
 * @Date: 2020-02-02 10:32:03
 * @Description: 
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXVAL = 1e9 + 10;
int findrange(int m, vector<pair<int,int>> vec){
    vector<int> dp(m+1, MAXVAL);
    dp[0] = 0;
    sort(vec.begin(), vec.end(), [](pair<int,int> a, pair<int, int> b){
        if(a.first < b.first){
            return true;
        }
        else if( a.first > b.first ){
            return false;
        }
        else{
            return a.second < b.second;
        }
    });
    for(int i = 0; i < vec.size(); ++i){
        int t1 = max(vec[i].first, 0);
        int t2 = min(vec[i].second, m);
        for(int j = t1; j <= t2; ++j){
            dp[j] = min(dp[j], dp[t1] + 1);
        }
    }
    return dp[m] == MAXVAL ? -1 : dp[m];
}

int main(){
    int n, m;
    cin >> n >> m;
    int t1, t2;
    vector<std::pair<int,int> > vec;
    for(int i = 0; i < n ; ++i){
        cin >> t1 >> t2;
        vec.push_back({t1, t2});
    }
    printf("%d\n",findrange(m, vec));
    return 0;
}