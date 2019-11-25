/*
 * @Author: haha_giraffe
 * @Date: 2019-11-25 14:47:15
 * @Description: 求字符串数组中的最长公共前缀
 */
/* 
    解题思路：最好想到的方法就是水平扫描，取最短的字符串最为参考模板，每次遍历后面的字符串比较，主要有一个字符不同则退出返回。
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        sort(strs.begin(),strs.end(),[](string a, string b){
            if(a.size() < b.size()){
                  return true;
            }  
            return false;
        });
        int n = strs[0].size();
        string res;
        for(int i=0;i<n;++i){
            char tmp = strs[0][i];
            bool flag = true;
            for(int j=1;j<strs.size();++j){
                if(tmp != strs[j][i]){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                break;
            }
            res += tmp;
        }
        return res;
        
    }
};

