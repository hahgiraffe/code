/*
 * @Author: haha_giraffe
 * @Date: 2019-11-26 11:50:18
 * @Description: 有效的数独
 * 判断一个 9x9 的数独是否有效。同时满足三个要求即为有效。
（1）数字 1-9 在每一行只能出现一次。
（2）数字 1-9 在每一列只能出现一次。
（3）数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 */

/* 
    方法一：死算，遍历三次board分别判断行、列、格子是否有重复的
    方法二：hash，给每个行、列、格子准备一个hash，遍历一遍board，插入并判断三次
    经验总结，当遇到数字去重这种问题，先要想到hash映射，再想set/map之类的STL
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        //行
        for(int i  = 0;i < n;++i){
            set<int> s;
            int num = 0;
            for(int j = 0; j < m ;++j){
                if(board[i][j]<='9' && board[i][j]>'0'){
                    num++;
                    s.insert(board[i][j]-'0');
                }
            }
            if(s.size() != num){
                return false;
            }
        }
        //列
        for(int j=0; j<m; ++j){
            set<int> s;
            int num = 0;
            for(int i = 0; i < n ;++i){
                if(board[i][j]<='9' && board[i][j]>'0'){
                    num++;
                    s.insert(board[i][j]-'0');
                }
            }
            if(s.size() != num){
                return false;
            }
        }
        //格子
        for(int i=0; i<n; i=i+3){
            for(int j=0; j<m; j=j+3){
                set<int> s;
                int num = 0;
                for(int p = 0;p<3;++p){
                    for(int q=0;q<3;++q){
                        if(board[i+p][j+q]<='9' && board[i+p][j+q]>'0'){
                            num++;
                            s.insert(board[i+p][j+q]-'0');
                        }
                    }
                }
                if(s.size() != num){
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[10][10];
        int col[10][10];
        int gezi[3][3][10];
        //注意memset初始化
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(gezi,0,sizeof(gezi));
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j]=='.') continue;
                int num = board[i][j]-'0';
                //这里同时累加并判断三个条件
                if( ++row[i][num] > 1 || ++col[j][num] > 1 || ++gezi[i/3][j/3][num] > 1){
                    return false;
                }
            }
        }
        return true;
    }
};