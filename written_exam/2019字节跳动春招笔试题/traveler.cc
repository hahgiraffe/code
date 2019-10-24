/*
 * @Description: 旅行商问题
 * @Author: hahagiraffe
 * @Date: 2019-07-30 12:01:37
 */

#include <vector>
#include <iostream>
using namespace std;
bool check(vector<int> go,int n){
    int num=0;
    for(int i=0;i<n;i++){
        num+=go[i];
    }
    return num==4?true:false;
}
void find(vector<vector<int>> dist,vector<int>& go,int& res,int sum,int last,int n){
    if(check(go,n)){
        sum+=dist[0][last];//这里返回原点
        if(sum<res){
            res=sum;
            return;
        }
    }
    for(int i=0;i<n;i++){
        if(go[i]==0){
            go[i]=1;
            find(dist,go,res,sum+dist[last][i],i,n);
            go[i]=0;
        }
    }
    return;
}
int main(){
    /*输入点个数，和每两个点之间的权值矩阵，如
    4
    0 2 6 5
    2 0 4 4
    6 4 0 2
    5 4 2 0
    */
    int n;
    cin>>n;
    vector<vector<int>> dist(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dist[i][j];
        }
    }
    int res=__INT_MAX__;
    vector<int> go(n,0);
    go[0]=1;
    int sum=0;
    int last=0;
    find(dist,go,res,sum,last,n);
    cout<<res;
    return 0;
}