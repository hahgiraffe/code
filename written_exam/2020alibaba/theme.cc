/*
 * @Author: haha_giraffe
 * @Date: 2020-03-20 11:39:28
 * @Description: 
 */
/* 
    题目：给定n个xx旋律字符串（全小写英文字符），xx旋律定义为非递减序列，要求把n个xx旋律拼接成一个最长的xx旋律，输出最长的xx旋律长度
*/
#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct node{
    char first, last;
    int len;
};

int n;
int g[26][26];  //g[i][j]表示以i字符开头，j字符结尾的最长旋律长度，dp[i][i]可以累加
int dp[26];     //dp[i]表示拼接后以i字符结尾的最长旋律长度

int main(){
    cin >> n;
    vector<node> strs;
    for(int i = 0; i < n; ++i){
        node state;
        string t;
        cin >> t;
        state.first = t[0];
        state.last = t[t.size() - 1];
        state.len = t.size();
        strs.push_back(state);
        if(state.first == state.last){
            g[state.first - 'a'][state.last - 'a'] += t.size();
        } else {
            g[state.first - 'a'][state.last - 'a'] = max(g[state.first - 'a'][state.last - 'a'], int(t.size()));
        }

    }
    dp[0] = g[0][0];
    
    for(int i = 1; i < 26; ++i){
        int t = g[i][i];
        for(int j = 0; j < i; ++j){
            dp[i] = max(dp[i], dp[j] + g[j][i]);
        }
        dp[i] += t;
    }
    int res = 0;
    for(int i = 0; i < 26; ++i){
        res = max(res, dp[i]);
    }
    printf("%d\n", res);
    return 0;
}