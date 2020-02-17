/*
 * @Author: haha_giraffe
 * @Date: 2020-02-17 19:58:52
 * @Description: 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
 * 如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。
 */

/* 
    解题思路：这题目太经典了，思路很简单，直接DFS，难点在于边界条件的控制，这道题目可以把所有的边界条件放到递归结束条件(dfs一开始)，然后每次dfs直接进去即可
*/
class Solution {
public:
    int idx[4] = {-1, 0, 0, 1};
    int idy[4] = {0, 1, -1, 0};
    void dfs(vector<vector<char>>& board, string word, int i, int j, vector<vector<bool>>& gone, int index, bool& res){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || gone[i][j] == true || res == true || board[i][j] != word[index]){
            return;
        }
        if(index == word.size() - 1){
            res = true;
            return;
        }
        gone[i][j] = true;
        
        for(int k = 0; k < 4; ++k){
            int nx = i + idx[k];
            int ny = j + idy[k];
            dfs(board, word, nx, ny, gone, index+1, res);
        }
        gone[i][j] = false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> gone(n, vector<bool>(m, false));
        int index = 0;
        bool res = false;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[i][j] == word[index]){
                    dfs(board, word, i, j, gone, index, res);
                    if(res){
                        return true;
                    }
                }
            }
        }
        return res;
    }
};