/*
 * @Author: haha_giraffe
 * @Date: 2020-01-12 17:24:25
 * @Description: 用以太网线缆将 n 台计算机连接成一个网络，计算机的编号从 0 到 n-1。线缆用 connections 表示，其中 connections[i] = [a, b] 连接了计算机 a 和 b。
                网络中的任何一台计算机都可以通过网络直接或者间接访问同一个网络中其他任意一台计算机。
                给你这个计算机网络的初始布线 connections，你可以拔开任意两台直连计算机之间的线缆，并用它连接一对未直连的计算机。请你计算并返回使所有计算机都连通所需的最少操作次数。如果不可能，则返回 -1 。 
 */

/* 
    解题思路：这题首先是判断是否连通，最好的方法就是并查集，然后直接套模板，最后还剩下n个连通块，就需要n-1个条边
    并查集getFather和mergeFather模板
*/

const int MAX = 1e5 + 50;
int fa[MAX];
class Solution {
public:
    int getFather(int x){
        return fa[x] = (fa[x] == x ? x : getFather(fa[x]));
    }
    int mergeFather(int x, int y){
        int fax = getFather(x);
        int fay = getFather(y);
        if(fax == fay) return false;
        if(fax > fay) swap(fax, fay);
        fa[fax] = fay;
        return true;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int num = connections.size();
        if(num < n - 1) return -1;
        for(int i = 0; i < n; ++i){
            fa[i] = i;
        }
        int res = n;    //连通块
        for(int i = 0; i < connections.size(); ++i){
            int a = connections[i][0];
            int b = connections[i][1];
            if(mergeFather(a, b)) res--;
        }
        return res - 1;
    }
};