/*
 * @Description: 格式化字符串，对于每一个字符串，①删除连续三个一样的字符中最后一个，如aaa->aa，②删除连续两对中最后一个字符，如AABB->AAB
 * @Author: hahagiraffe
 * @Date: 2019-07-30 11:38:45
 */
#include <string>
#include <iostream>
using namespace std;

void check(string& str){
    for(int i=0;i<str.size();i++){
        while(i+2<str.size() && str[i]==str[i+1] && str[i+1]==str[i+2]){
            auto it=str.begin();
            str.erase(it+i+2);
        }
        while(i+3<str.size() && str[i]==str[i+1] && str[i+2]==str[i+3]){
            auto it=str.begin();
            str.erase(it+i+3);
        }
    }
    return;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        check(str);
        cout<<str<<endl;
    }
}