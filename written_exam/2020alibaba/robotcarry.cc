/*
 * @Author: haha_giraffe
 * @Date: 2020-03-19 14:50:59
 * @Description: 
 */
/* 
    题目描述:
    在自动化仓库中有若干障碍物，机器人需要从起点出发绕过这些障碍物到终点搬取货柜，现试求机器人从起点运动到终点用时最短的路径。
    已知机器人只能沿着东西方向或南北方向移动，移动的速度为1m/s，机器人每转向90度需要花费1s。

    输入：
    第一行：起点位置坐标及机器人朝向，如： 
    1 0 EAST 
    代表机器人初始坐标为x=1,y=0，机器人面朝东方 
    第二行：终点位置坐标及机器人朝向，如： 
    0 2 WEST 
    代表机器人需要移动至点x=0,y=2，且面朝西方 
    接下来输入的是地图： 
    首先是两个数字r,c，代表有地图数据有多少行与多少列，如： 
    2 3 
    0 1 0 
    0 0 0 
    其中，左上角为坐标原点，从左向右为x轴增大的方向是东方，从上到下为y轴增大的方向是南方。 
    地图中1代表有障碍物，机器人不能前往，0代表无障碍物机器人可以前往 地图中相邻的每两个点之间的距离为1m。 
    0 <= l,w <= 128

    输出：
    机器人从起点移动到终点所需要的最短秒数，当不可达时输出65535

*/


/* 
    解题思路:bfs,用一个queue存储,三维数组,表示横、纵、当前方向。注意方向变化的时候同样需要变化一个状态放进队列中,同时step+1,
*/
#include <vector>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int getdirection(string dir){
    if(dir == "EAST"){
        return 0;
    }
    if(dir == "SOUTH"){
        return 1;
    }
    if(dir == "WEST"){
        return 2;
    }
    return 3;
}

struct Point{
    int x, y, d;
    int step;
    Point(int x, int y, int d, int step) : x(x), y(y), d(d), step(step){ }
};

int main(){
    int startx, starty;
    string startdir, enddir;
    int endx, endy;
    cin >> startx >> starty >> startdir;
    cin >> endx >> endy >> enddir;
    int startd = getdirection(startdir);
    int endd = getdirection(enddir);
    int n , m;
    cin >> n >> m;
    int vec[130][130][4];
    bool gone[130][130][4];
    memset(gone, false, sizeof(gone));
    memset(vec, 0, sizeof(vec));
    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> vec[i][j][0];
            for(int k = 1; k < 4; ++k){
                vec[i][j][k] = vec[i][j][0];
            }
        }
    }
    queue<Point> q;
    Point start(startx, starty, startd, 0);
    q.push(start);
    while(!q.empty()){
        Point p = q.front();
        if(p.x == endx && p.y == endy && p.d == endd){
            cout << p.step << endl;
            break;
        }
        q.pop();
        int nx = p.x, ny = p.y, nd = p.d;
        switch(p.d){
            case 0 : nx = p.x + 1; break;
            case 1 : ny = p.y + 1; break;
            case 2 : nx = p.x - 1; break;
            default : ny = p.y - 1; break;
        }
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && vec[nx][ny][nd] == 0 && !gone[nx][ny][nd]){
            gone[nx][ny][nd] = true;
            q.push(Point(nx, ny, nd, p.step+1));
        }
        nx = p.x, ny = p.y;
        int d[2] = {-1, 1};
        for(int i = 0; i < 2; ++i){
            nd = (p.d + d[i]) % 4;
            if(!gone[nx][ny][nd]){
                gone[nx][ny][nd] = true;
                q.push(Point(nx, ny, nd, p.step+1));
            }
        }
    }
    if(q.empty()) cout << 65535 << endl;
    return 0;
}