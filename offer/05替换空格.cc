/*
 * @Author: haha_giraffe
 * @Date: 2020-02-15 20:20:07
 * @Description: 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 */
class Solution {
public:
    string replaceSpace(string s) {
        int n = s.size();
        string res;
        for(auto a : s){
            if(a == ' '){
                res += "%20";
            }
            else{
                res += a;
            }
        }
        return res;
    }
};