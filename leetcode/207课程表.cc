/*
 * @Author: haha_giraffe
 * @Date: 2020-01-06 19:10:46
 * @Description: 现在你总共有 n 门课需要选，记为 0 到 n-1。
    在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
    给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？
 */

/* 
    解题思路：拓扑排序。重中之重，可以当做模板题，一个邻接表和一个vector用来记录入度。
    首先记录入度， 然后bfs，用一个队列存放入度为0的节点，
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        if(!n) return true;
        //记录入度
        vector<int> indegree(numCourses, 0);
        //记录邻接表
        vector<vector<int>> vec(numCourses, vector<int>());
        
        //拓扑排序
        queue<int> que;
        for(int i = 0; i < n; ++i){
            indegree[prerequisites[i][0]]++;
            vec[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(int i = 0; i < numCourses; ++i){
            if(indegree[i] == 0){
                que.push(i);
            }
        }
        vector<int> res;
        while(!que.empty()){
            int tmp = que.front();
            que.pop();
            res.push_back(tmp);
            for(auto& a : vec[tmp]){
                indegree[a]--;
                if(indegree[a] == 0){
                    que.push(a);
                }
            }
        }
        return res.size() == numCourses;
    }
};