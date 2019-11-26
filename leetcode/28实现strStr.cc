/*
 * @Author: haha_giraffe
 * @Date: 2019-11-26 08:47:46
 * @Description: 实现strStr()
 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
 */

/* 
    解题思路：裸kmp，kmp分为两个步骤，第一步根据目标串得到next数组(第一个元素默认为-1，长度为pstr.size())
    得到next后再进行匹配，如果不匹配则 j = next[j]
*/
class Solution {
public:
    vector<int> findnext(string b){
        vector< int> next;
        next.push_back(-1);
        int i=0,k=-1;
        while(i< b.size()-1){
            if(k==-1 || b[i]==b[k]){
                i++;
                k++;
                next.push_back(k);
            }
            else{
                k=next[k];
            }
        }
        return next;
    }
    int strStr(string a, string b){
        if( b.empty()){
            return 0;
        }
        int n=a.size();
        int m=b.size();
        int i=0,j=0;
        vector< int> next = findnext(b);
        while(i< n && j< m){
            if(j==-1 || a[i] == b[j]){
                i++;
                j++;
            }
            else{
                j = next[j];
            }
        }
        if(j==m){
            return i-j;
        }
        return -1;
    }
};