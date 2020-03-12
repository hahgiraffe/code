/*
 * @Author: haha_giraffe
 * @Date: 2020-03-09 19:33:33
 * @Description: 
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