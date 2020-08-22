/*
 * @Author: haha_giraffe
 * @Date: 2020-02-02 11:12:21
 * @Description: 字符串解码
 */

//先找到']',然后向前找'['和'|'，分别标记，最后替换字符串
#include <iostream>
#include <string>
using namespace std;

string unpack(string s){
    int i = 0;
    while(i < s.size()){
        if(s[i] == ']'){
            int j = i;
            int k = 0;
            while(s[j] != '['){
                if(s[j] == '|'){
                    k = j;
                }
                j--;
            }
            int len = stoi(s.substr(j+1, k - j - 1));
            string s1 = s.substr(k+1, i - k -1);
            string s2;
            for(int si = 0; si < len; ++si){
                s2 += s1;
            }
            s = s.replace(j, i-j+1, s2);
            i = j;
        }
        i++;
    }
    return s;
}

int main(){
    string s;
    cin >> s;
    cout << unpack(s) << endl;
    return 0;
}