/*
 * @Author: haha_giraffe
 * @Date: 2020-03-26 09:39:22
 * @Description: 
 */
/* 
第一题，给定一个数组n，比如
5 9  5 4  4
4 7  4 10 3
2 10 9 2  3
从每一列选择一个数，求出后一列减去前一列的绝对值的和的最小值  
比如这里就是5 7 5 4 4，所以输出是5 
*/
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

const int MAXN = 100005;
typedef long long ll;
ll num[MAXN][5];
ll dp[MAXN][5];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= 3; ++j){
            cin >> num[i][j];
        }
    }
    memset(dp, 0x3f3f3f3f,sizeof(dp));
    dp[1][1] = 0;
    dp[1][2] = 0;
    dp[1][3] = 0;
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= 3; ++j){
            dp[i][1] = min(dp[i][1], dp[i-1][j] + abs(num[j][i-1] - num[1][i]));
            dp[i][2] = min(dp[i][2], dp[i-1][j] + abs(num[j][i-1] - num[2][i]));
            dp[i][3] = min(dp[i][3], dp[i-1][j] + abs(num[j][i-1] - num[3][i]));
        }
    }
    ll ans = min(dp[n][1], min(dp[n][2], dp[n][3]));
    cout << ans << endl;
    return 0;
}