/*
 * @Author: haha_giraffe
 * @Date: 2020-03-20 10:41:39
 * @Description: 
 */
/* 
    题目：给你扑克牌A~10,每张牌最多4张。然后打牌有4个规则。规则一：单张，规则二：对子，规则三：5张顺子，规则四：3连对。问，打完手牌的最少出牌次数。
*/
#include <vector>
#include <map>

using namespace std;

vector<int> a;
map<vector<int>, int> dp;

int dfs(vector<int>& tmp){
    if(dp.find(tmp) != dp.end()){
        return dp[tmp];
    }
    bool finish = true;
    for(int i = 0; i < 10; ++i){
        if(tmp[i] != 0){
            finish = false;
            break;
        }
    }
    if(finish == true){
        dp[tmp] = 0;
        return 0;
    }
    int state = -1;
    for(int i = 0; i < 10; ++i){
        if(tmp[i] > 0){
            state = i;
            break;
        }
    }
    int res = 0x7f7f7f;
    //case 1 出单张
    tmp[state] -= 1;
    res = min(res, dfs(tmp) + 1);
    tmp[state] += 1;
    //case 2 出对子
    if(tmp[state] >= 2){
        tmp[state] -= 2;
        res = min(res, dfs(tmp) + 1);
        tmp[state] += 2;
    }
    //case 3 五张顺子
    if(state + 4 < 10){
        bool test = true;
        for(int j = state; j <= state + 4; ++j){
            if(tmp[j] == 0){
                test = false;
                break;
            }
        }
        if(test){
            for(int j = state; j <= state + 4; ++j){
                tmp[j] -= 1;
            }
            res = min(res, dfs(tmp) + 1);
            for(int j = state; j <= state + 4; ++j){
                tmp[j] += 1;
            }
        }
    }
    //case 4 三个连对
    if(state + 2 < 10){
        bool test = true;
        for(int j = state; j <= state + 2; ++j){
            if(tmp[j] < 2){
                test = false;
                break;
            }
        }
        if(test){
            for(int j = state; j <= state + 2; ++j){
                tmp[j] -= 2;
            }
            res = min(res, dfs(tmp) + 1);
            for(int j = state; j <= state + 2; ++j){
                tmp[j] += 2;
            }
        }
    }

    dp[tmp] = res;
    return res;
}

int main(){
    int n = 10;
    a = vector<int>(10, 2);
    // for(int i = 0; i < 10; ++i){
    //     scanf("%d", &a[i]);
    // }    
    int res = dfs(a);
    printf("%d\n", res);
    return 0;
}