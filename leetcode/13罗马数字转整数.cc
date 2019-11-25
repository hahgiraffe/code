/*
 * @Author: haha_giraffe
 * @Date: 2019-11-25 14:42:08
 * @Description: 罗马数字转成整数
 */
/* 
    解题思路：首先把两个字符的特例和一个字符的用map表示出来，然后遍历字符串依次匹配即可
*/
class Solution {
public:
    int romanToInt(string s) {
        map<string,int> m={
            {"IV",4},
            {"IX",9},
            {"XL",40},
            {"XC",90},
            {"CD",400},
            {"CM",900},
        };
        map<char,int> m2 ={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        int res = 0;
        int index = 0;
        while(index<s.size()){
            if(index+1<s.size() && m.find(s.substr(index,2))!=m.end()){
                res += m[s.substr(index,2)];
                index+=2;
            }
            else{
                res+=m2[s[index]];
                index++;
            }
        }
        return res;
    }
};