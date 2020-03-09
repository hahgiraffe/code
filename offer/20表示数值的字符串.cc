/*
 * @Author: haha_giraffe
 * @Date: 2020-03-09 11:19:33
 * @Description: 验证给定的字符串是否可以解释为十进制数字。
 */
/* 
    这道题目和atoi不一样，但是相似，要考虑很多情况，测试用例如下
    "0" => true
    " 0.1 " => true
    "abc" => false
    "1 a" => false
    "2e10" => true
    " -90e3   " => true
    " 1e" => false
    "e3" => false
    " 6e-1" => true
    " 99e2.5 " => false
    "53.5e93" => true
    " --6 " => false
    "-+3" => false
    "95a54e53" => false

*/
class Solution {
public:
    //检验底数
    bool checkp(string s){
        bool res = false, point = false;    //这里res默认为false，是排除"."的情况
        int n = s.size();
        for(int i = 0; i < n; ++i){
            if(s[i] == '+' || s[i] =='-'){
                if(i != 0) return false;
            } else if(s[i] == '.'){
                if(point) return false;
                point = true;
            } else if (s[i] < '0' || s[i] > '9'){
                return false;
            } else {
                res = true;
            }
        }
        return res;
    }
    //检验指数
    bool checks(string s){
        bool res = false;   //这里默认为false是排除，只有"e"的情况
        int n = s.size();
        for(int i = 0; i < n; ++i){
            if(s[i] == '+' || s[i] =='-'){
                if(i != 0) return false;
            } else if (s[i] < '0' || s[i] > '9'){
                return false;
            } else {
                res = true;
            }
        }
        return res;
    }
    
    bool isNumber(string s) {
        //首先去掉首尾空字符
        int i = s.find_first_not_of(' ');
        if(i == string::npos) return false;
        int j = s.find_last_not_of(' ');
        s = s.substr(i, j - i + 1);
        if(s.empty()) return false;
        int idx = s.find('e');
        if(idx == string::npos){
            return checkp(s);
        } else {
            return checkp(s.substr(0, idx)) && checks(s.substr(idx+1));
        }
    }
};