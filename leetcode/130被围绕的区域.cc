/*
 * @Author: haha_giraffe
 * @Date: 2019-12-16 21:43:38
 * @Description: 被围绕的区域
 */
/* 
    经典题，也可以算图中有多少个孤岛。这种方法的好处在于从边界点出发，把边界和与其相连的先指出来，然后就不用中间遍历了。
*/
class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i>=0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == 'O'){
            board[i][j] = '1';
            dfs(board, i+1, j);
            dfs(board, i-1, j);
            dfs(board, i, j+1);
            dfs(board, i, j-1);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; ++i){
            dfs(board, i, 0);
            dfs(board, i, m-1);
        }
        for(int j=0; j<m; ++j){
            dfs(board, 0, j);
            dfs(board, n-1, j);
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(board[i][j] == '1'){
                    board[i][j] = 'O';
                }
                else{
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};