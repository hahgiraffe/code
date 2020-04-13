/*
 * @Author: haha_giraffe
 * @Date: 2020-03-16 09:21:50
 * @Description: 模式匹配
 */
#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<int> getarr(string b){
    int len = b.size();
    vector<int> res;
    int i = 0, k = -1;
    res.push_back(-1);
    while(i < len -1){
        if(k == -1 || b[i] == b[k]){
            i++; k++;
            res.push_back(k);
        } else {
            k = res[k];
        }
    }
    return res;
}


int kmp(string a, string b){
    int lena = a.size();
    int lenb = b.size();
    vector<int> next = getarr(b);
    int i = 0, j = 0;
    while(i < lena && j < lenb){
        if(j == -1 || a[i] == b[j]){
            i++;j++;
        } else {
            j = next[j];
        }
    }
    if(j == lenb){
        return i-j;
    }
    return -1;
}

int main(){
    string a = "asfawgafaferarqrda";
    string b = "fera";
    cout << kmp(a, b);    
    return 0;
}