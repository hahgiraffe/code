/*
 * @Author: haha_giraffe
 * @Date: 2020-02-02 10:03:27
 * @Description: 找楼
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> findbuilding(int n, vector<int> vec){
    vector<int> res;
    for(int i = 0; i < n; ++i){
        int left = i - 1, right = i + 1;
        int tmp = 0;
        int maxleft = 0, maxright = 0;
        while(left >= 0){
            if(vec[left] >= maxleft){
                tmp++;
                maxleft = vec[left];
            }
            left--;
        }
        while(right < n){
            if(vec[right] >= maxright){
                tmp++;
                maxright = vec[right];
            }
            right++;
        }
        res.push_back(tmp+1);
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> vec;
    int tmp;
    for(int i = 0 ; i < n; ++i){
        cin >> tmp;
        vec.push_back(tmp);
    }
    vector<int> res = findbuilding(n,vec);
    for(int i = 0 ; i < res.size(); ++i){
        if(i == 0){
            printf("%d",res[i]);
        }
        else{
            printf(" %d",res[i]);
        }
    }
    return 0;
}