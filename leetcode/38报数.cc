/*
 * @Author: haha_giraffe
 * @Date: 2019-11-27 17:16:59
 * @Description: 报数
 * 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
    1.     1
    2.     11
    3.     21
    4.     1211
    5.     111221
 */

/*  
    解题思路：死算，贪心法按照每位查找即可
*/
class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        if(n==1){
            return s;
        }
        for(int i=1;i<n;++i){
            char c=s[0];
            int num=1;
            string tmp;
            for(int j=1;j<s.size();++j){
                if(s[j]==c){
                    num++;
                }
                else{
                    tmp+=to_string(num);
                    tmp+=c;
                    c=s[j];
                    num=1;
                }
            }
            tmp+=to_string(num);
            tmp+=c;
            s=tmp;
        }
        return s;
    }
};
