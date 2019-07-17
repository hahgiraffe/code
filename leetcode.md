笔记用于记录leetcode刷题的想法，用于总结和回顾，根据类型进行分，相同类型依照题号排列
2019-7-12

一、数组
 
二、二叉树

三、字符串

四、链表

(82)/(83) Remove Duplicates from Sorted List
  在排序好的链表中删除重复的数字，82是保留一个，83是重复数字不保留,基本思路都是双指针，83再加一个set用来存储重复的数字即可，然后再遍历一遍删除即可。

五、哈希表

五、DFS

(51) / (52) N-Queens
 N皇后是非常经典的题目，题目要求在棋盘上放置皇后，横竖斜都不相邻，主要思想是dfs，用一个vector<int> arr存储第n行的皇后位于arr[n]列，递归返回条件是arr.size() == n ,如果满足条件则找到一个，如果没有达到条件则继续尝试。

六、动态规划（DP）


七、排序相关

(147) Insert Sort List
    问题要求在链表中实现插入排序，重点在于链表中要存储一个节点now，但是要判断下一个节点的值才行now->next->val，在判断的时候首先要保证now->next存在

(148) Sort List
    问题要求在O(nlogn)时间复杂度下完成链表排序，因为链表快排和堆排序很不方便，只能用归并排序mergesort。
归并排序的思路是递归的将一个链表拆分成两个链表（快慢指针），然后两个链表合并。
    mergesort的时间复杂度都是O(nlogn)，空间复杂度因为有递归，栈也要算，所以空间复杂度为递归的次数O(logn)另外说一下，如果是数组mergesort，在两个数组合并时候要多用一个空间，所以其空间复杂度是O(n)，时间复杂度还是O(nlogn)

八、其他类型（位运算，二分法，贪心，双指针）

(146) LRU Cache
  这个问题最主要就是考虑好用什么数据结构，一般map+list，map<int key,int value>存储键值，list<int key>表示顺序，当新插入一个元素用list.push_front()，如果超过capacity则需先list.pop_back()，当要更新位置的时候，则要先list.remove(key)，再list.push_front(key)



