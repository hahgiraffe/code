/*
 * @Author: haha_giraffe
 * @Date: 2020-02-02 11:12:21
 * @Description: 字符串解码
 */
#include <bits/stdc++.h>
using namespace std;
string unpack(string str){
    string res;
    int n = str.size();
    stack<int> s;
    int i = 0;
    while(i < n){
        if(str[i] == '['){
            s.push(i);
            string substr;
            while(!s.empty() && i < n){
                if(str[i] == '['){
                    s.push(i);
                }
                else if(str[i] == ']'){
                    int tmpleft = s.top();
                    int tmpright = i;
                    s.pop();
                    
                }
                i++;
            }
            res += substr;
        }
        else{
            res += str[i];
        }
        i++;
    }
    return res;
}

int main(){
    string str;
    cin >> str;
    printf("%s\n", unpack(str));
    return 0;
}