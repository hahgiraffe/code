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

int main(){
    vector<int> abs{5,7,6,9,11,10,8};
    cout<<VerifySquenceOfBST(abs);
}