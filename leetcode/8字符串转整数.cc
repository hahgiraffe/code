/*
 * @Author: haha_giraffe
 * @Date: 2019-10-26 10:50:47
 * @Description: 经典atoi
 */

/*
    题目解析：这道题要注意的地方很多
        1.去开头的空字符
        2.判断正负号
        3.计算数字是否溢出
 */

//虽然我这个写出来了，但是尝试了很多次，面试的时候肯定不行
class Solution {
public:
    int myAtoi(string str) {
        long long res = 0;
        int index = 0;
        bool isbegin = true;
        bool bigzero = true;
        while(index<str.size()){
            if(str[index]==' ' && isbegin){
                //去除空开头
                index++;
                continue;
            }
            if(str[index]=='-' || str[index]=='+'){
                //一开始为负数
                if(isbegin){
                    if(str[index]=='-') bigzero = false;
                    index++;
                    isbegin = false;
                    continue;
                }
                else{
                    break;
                }
            }
            if(str[index]=='0' && isbegin){
                //首字母为0
                index++;
                isbegin = false;
                continue;
            }
            if(str[index]<='9' && str[index]>='0'){
                if(bigzero && res>INT_MAX/10){
                    return INT_MAX;
                }
                if(bigzero==false && -res<INT_MIN){
                    return INT_MIN;
                }
                res = res*10 +str[index]-'0';
                
            }
            else{
                if(isbegin){
                    return 0;
                }
                else{
                    break;
                }
            }
            isbegin = false;
            index++;
        }
        if(bigzero){
            if(res>INT_MAX){
                return INT_MAX;
            }
            return res;
        }
        else{
            if(-res<INT_MIN){
                return INT_MIN;
            }
            return -res;
        }
    }
};

// 这里是别人写的更简洁的版本
// class Solution {
// public:
//     int myAtoi(string str) {
//         int res = 0;
//         int i = 0;
//         int flag = 1;
//         // 1. 检查空格
//         while (str[i] == ' ') { i++; }
//         // 2. 检查符号
//         if (str[i] == '-') { flag = -1; }
//         if (str[i] == '+' || str[i] == '-') { i++; }
//         // 3. 计算数字
//         while (i < str.size() && isdigit(str[i])) {
//             int r = str[i] - '0';
//             // 4. 处理溢出，这是关键步骤
//             if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7)) { return flag > 0 ? INT_MAX : INT_MIN; }
//             res = res * 10 + r;
//             i++;
//         }
//         return flag > 0 ? res : -res;
//     }
// };
