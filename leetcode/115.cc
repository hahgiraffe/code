/*
 * @Description: 这个dfs超时了
 * @Author: haha_giraffe
 * @Date: 2019-08-14 09:23:36
 */
#include <bits/stdc++.h>
using namespace std;
void dfs(string s,string t,int indexs,int& indext,int& num){
    if(indext==t.size()){
        num++;
        return;
    }
    for(int i=indexs;i<s.size();i++){
        if(s[i]==t[indext]){
            indext++;
            dfs(s,t,i+1,indext,num);
            indext--;
            cout<<"----"<<endl;
        }
    }
    return;
}
int numDistinct(string s, string t) {
    if(s.size()<t.size()){
        return 0;
    }
    int indexs=0;
    int indext=0;
    int num=0;
    dfs(s,t,indexs,indext,num);
    return num;
}
int main(){
    string s,t;
    cin>>s>>t;
    cout<<numDistinct(s,t);
}