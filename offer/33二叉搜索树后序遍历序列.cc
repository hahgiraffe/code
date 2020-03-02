/*
 * @Author: haha_giraffe
 * @Date: 2020-02-27 20:53:32
 * @Description: 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
 * 如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
 */
/* 
    解题思路：二叉搜索树左子树小于节点，右子树大于节点，而后序遍历则是左右根，找到序列最后一个节点，并且找到分界节点，递归即可
*/
class Solution {
public:
    bool dfs(int left, int right, vector<int>& postorder){
        if(left >= right){
            return true;
        }
        int tmp = right;
        int val = postorder[right];
        for(; tmp >= 0; --tmp){
            if(postorder[tmp] < val){
                break;
            }
        }
        int ind = tmp;
        for(; tmp >= 0; --tmp){
            if(postorder[tmp] > val){
                return false;
            }
        }
        return dfs(left, ind, postorder) && dfs(ind+1, right-1, postorder);
    }
    bool verifyPostorder(vector<int>& postorder) {
        return dfs(0, postorder.size()-1, postorder);
    }
};