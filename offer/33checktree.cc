/*
 * @Author: haha_giraffe
 * @Date: 2020-03-09 19:33:33
 * @Description: 
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
 */
#include <vector>
#include <iostream>
using namespace std;

bool dfs(vector<int>& sequece, int b, int e)
{
    if(b==e)
    {
        return true;
    }
    int mid = b;
    while(sequece[mid++]<sequece[e] && mid<e);

    int tmp = mid;
    while (sequece[tmp++]>sequece[e] && tmp<e);
    if(tmp<e)
    {
        return false;
    }

    if(mid==b || mid==e)
    {
        return dfs(sequece, b, e-1);
    }
    else
    {
        return (dfs(sequece, b, mid-1) && dfs(sequece, mid, e-1));
    }
}
    
bool VerifySquenceOfBST(vector<int> sequence) {
    if(sequence.size()==1){
        return true;
    }
    bool res=false;
    res=dfs(sequence,0,sequence.size()-1);
    return res;
}

class myclas{
public:
    myclas(int a) : m_a(a){ }

private:
    const int m_a;
}

int main(){
    const int a = 2;
    vector<int> abs{5,7,6,9,11,10,8};
    cout<<VerifySquenceOfBST(abs);
}

/* 
这个方法更加好，递归思想，将最后一个值作为privot，找到左子树和右子树的分界点
注意考虑如果只有一个子树的情况
class Solution {
public:
    bool dfs(vector<int>& postorder, int l, int r){
        if(l >= r){
            return true;
        }
        int tmp = postorder[r];
        int index = l;
        for(int i = r-1; i >= l; --i){
            if(postorder[i] < tmp){
                index = i;
                break;
            }
        }
        if(index == l){
            return dfs(postorder, l, r-1);
        }
        for(int i = index; i >= l; --i){
            if(postorder[i] > tmp){
                return false;
            }
        }
        return dfs(postorder, l, index) && dfs(postorder, index+1, r-1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        return dfs(postorder, 0, postorder.size()-1);
    }
};
*/