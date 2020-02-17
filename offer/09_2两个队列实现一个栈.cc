/*
 * @Author: haha_giraffe
 * @Date: 2020-02-17 10:15:35
 * @Description: 两个队列实现一个栈
 */
#include <queue>
#include <stdio.h>
using namespace std;
class Solution{
public:
    Solution(){
        while(!q1.empty()){
            q1.pop();
        }
        while(!q2.empty()){
            q2.pop();
        }
    }
    
    void push(int target){
        if(!q1.empty()){
            q1.push(target);
        }
        else{
            q2.push(target);
        }
    }

    //直接返回吧
    int pop(){
        if(!q1.empty()){
            int len = q1.size();
            while(len-- > 1){
                int tmp = q1.front();
                q2.push(tmp);
                q1.pop();
            }
            int tmp = q1.front();
            q1.pop();
            return tmp;
        }
        else{
            int len = q2.size();
            while(len-- > 1){
                int tmp = q2.front();
                q1.push(tmp);
                q2.pop();
            }
            int tmp = q2.front();
            q2.pop();
            return tmp;
        }
    }

private:
    queue<int> q1;
    queue<int> q2;
};

int main(){
    Solution s;
    s.push(1);
    s.push(3);
    printf("%d\n",s.pop());
    printf("%d\n",s.pop());
    return 0;
}