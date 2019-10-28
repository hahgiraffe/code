/*
 * @Author: haha_giraffe
 * @Date: 2019-10-25 10:21:04
 * @Description: Z字形变化
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
L     D     R
E   O E   I I
E C   I H   N
T     S     G

 */

/* 这道题目只要头脑清晰就可以了，搞清楚啥时候往下走，啥时候往上走 */
class Solution {
public:
    string convert(string s, int numRows) {
        //一开始的想法就是放到一个二维数组里面，后面优化的时候发现可以直接vector<string>
        if(numRows==1 || s.empty()){
            return s;
        }
        vector<string> res(numRows);
        int m = numRows*2-2;
        for(int i=0;i<s.size();++i){
            int index = i%m;
            if(index<numRows){
                res[index]+=s[i];
            }
            else{
                res[m-index]+=s[i];
            }
        }
        string ans="";
        for(auto a:res){
            ans+=a;
        }
        return ans;
    }
};