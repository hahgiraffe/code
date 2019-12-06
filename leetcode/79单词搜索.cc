/*
 * @Author: haha_giraffe
 * @Date: 2019-12-06 22:10:23
 * @Description: 单词搜素
 */

/* 
    这是很经典的一道题目，一个dfs中进行搜索，重点在于边界条件要找好，什么时候退出，什么时候更进一步。
*/


class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int x, vector<vector<int>>& visited){
        if(i<0 || i>= board.size() || j<0 || j>=board[0].size() || x>=word.size() || board[i][j] != word[x] || visited[i][j]){
            return 0;
        }
        else if(x == word.size()-1 && board[i][j]==word[x]){
            return 1;
        }
        else{
            visited[i][j] = 1;
            bool m1 = dfs(board, i - 1, j, word, x + 1, visited);
            if(m1) return 1;
            bool m2 = dfs(board, i + 1, j, word, x + 1, visited);
            if(m2) return 1;
            bool m3 = dfs(board, i, j - 1, word, x + 1, visited);
            if(m3) return 1;
            bool m4 = dfs(board, i, j + 1, word, x + 1, visited);
            if(m4) return 1;
            visited[i][j] = 0;
            return 0;  
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0] && dfs(board, i, j, word, 0, visited)){
                    return 1;
                }
            }
        }
        return 0;
    }
};