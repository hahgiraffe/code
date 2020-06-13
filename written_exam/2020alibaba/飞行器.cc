/*
 * @Author: haha_giraffe
 * @Date: 2020-03-24 18:03:06
 * @Description: 
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n , m;
const int MAXN = 1000;
int vis[MAXN][MAXN];
char Map[MAXN][MAXN];
int step[MAXN][MAXN];

struct node{
    int x, y;
}beg, in, out;

int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1} 
};

int num = 5;

bool check(int x, int y){
    if(!vis[x][y] && x >= 1 && x <= n && y >= 1 && y <= m && Map[x][y] != '#'){
        return true;
    }
    return false;
}

int bfs(){
    vis[beg.x][beg.y] = 1;
    step[beg.x][beg.y] = 0;
    queue<node> q;
    q.push(beg);
    while(!q.empty()){
        out = q.front();
        q.pop();
        for(int i = 0; i < 5; ++i){
            if(i != 4){
                in.x = out.x + dir[i][0];
                in.y = out.y + dir[i][1];
            } else {
                in.x = n+1-out.x;
                in.y = n+1-out.y;
                num--;
                if(num < 0){
                    continue;
                }
            }
            if(check(in.x, in.y)){
                if(Map[in.x][in.y] == 'E'){
                    return step[out.x][out.y] + 1;
                }
                q.push(in);
                vis[in.x][in.y] == 1;
                step[in.x][in.y] = step[out.x][out.y] + 1;
            }
        }
    }
    return -1;
}

int main(){
    cin >> n >> m;
    for(int i  = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> Map[i][j];
            if(Map[i][j] == 'S'){
                beg.x = i;
                beg.y = j;
            }
        }
    }
    cout << bfs();
    return 0;
}