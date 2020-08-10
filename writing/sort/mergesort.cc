/*
 * @Description: mergesort
 * @Author: haha_giraffe
 * @Date: 2019-08-10 09:26:13
 */
#include <stdio.h>
#include <vector>
using namespace std;

void mergesort(vector<int>& res,vector<int>& vec,int begin,int end){
    if(begin>=end){
        return;
    }
    //int len=(end-begin)/2;
    int middle=(begin+end)/2;
    mergesort(res,vec,begin,middle);
    mergesort(res,vec,middle+1,end);
    int i=begin;
    int j=middle+1;
    int index=i;
    while(i<=middle && j<=end){
        if(vec[i]<vec[j]){
            res[index++]=vec[i++];
        }
        else{
            res[index++]=vec[j++];
        }
    }
    while(i<=middle){
        res[index++]=vec[i++];
    }
    while(j<=end){
        res[index++]=vec[j++];
    }
    //注意这里最后一定要把排序好的再放回原数组
    int num=begin;
    while(num<=end){
        vec[num]=res[num];
        num++;
    }
    return;
}
int main(){
    vector<int> arr{32,44,12,23,41,513,1,23,4,5,22,23,15};
    vector<int> res(arr);
    mergesort(res,arr,0,arr.size()-1);
    for(auto a:res){
        printf("%d ",a);
    }
    return 0;
}