/*
 * @Author: haha_giraffe
 * @Date: 2020-03-23 14:43:33
 * @Description: 
 */

#include <string>
#include <iostream>
using namespace std;

string bignumplus(string str1, string str2){
    if(str1.size() < str2.size()){
        string tmp = str1;
        str1 = str2;
        str2 = tmp;
    }
    int n1 = str1.size(), n2 = str2.size(), flag = 0;
    int sum, a , b;
    while(n1 > 0){
        a = str1[n1-1] - '0';
        if(n2 > 0){
            b = str2[n2 - 1] -'0';
        } else {
            b = 0;
        }
        sum = a + b + flag;
        if(sum >= 10){
            str1[n1 - 1] = '0' + sum % 10;
            flag = 1;
        } else {
            str1[n1 - 1] = '0' + sum;
            flag = 0; 
        }
        n1--;
        n2--;
    }
    if(flag == 1){
        str1 = "1" + str1;
    }
    return str1;
}

int main(){
    string str1 = "141423";
    string str2 = "352423443";
    cout << bignumplus(str1, str2) << endl;
    return 0;
}