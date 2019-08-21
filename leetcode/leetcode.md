<!--
 * @Description: leetcode刷题记录
 * @Author: haha_giraffe
 * @Date: 2019-08-14 10:12:35
 -->
# leetcode 刷题记录
  本笔记用于记录leetcode刷题的想法，用于总结和回顾，根据类型进行分，相同类型依照题号排列
---
1. 数组

 
2. 二叉树

3. 字符串
（131） Palindrome Partitioning
    给定一个字符串，分割其每个子串为一个回文字符串。回溯法暴力搜索，从头往后遍历字符串，如果找到一个是回文，则dfs继续后面的，注意substr是[begin,end)
（132） Palindrome Partitioning II
    求能分割成的子回文字符串，最少切的刀数，如果按照131的方法会超时，所以只能用两个dp，第一个dp[i][j]判断字符串str(i,j)是否为回文，dp[i][j]=(s[i]==s[j]) && dp[i+1]dp[j-1]
    第二个dp f[n]表示前n个字符中，最少可以分割几个回文子串 如果dp[k][n-1]是回文，则f[n]=max(f[n],f[n-k]+1)
4. 链表

(82)/(83) Remove Duplicates from Sorted List
  在排序好的链表中删除重复的数字，82是保留一个，83是重复数字不保留,基本思路都是双指针，83再加一个set用来存储重复的数字即可，然后再遍历一遍删除即可。

5. 哈希表

6. DFS

(51) / (52) N-Queens
    N皇后是非常经典的题目，题目要求在棋盘上放置皇后，横竖斜都不相邻，主要思想是dfs，用一个vector arr存储第n行的皇后位于arr[n]列，递归返回条件是arr.size() == n ,如果满足条件则找到一个，如果没有达到条件则继续尝试。

7. 动态规划（DP）
（000） 01背包问题
    有n个背包，每个背包有weight和value，且只能选一次在给定的W下，求最大的V，dp[i][j]表示在前i个物品背包容量j的情况下最大的价值,每个背包有两个状态，取或者不取
    状态方程 dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);(当j>weight[i]时，如果小于直接dp[i][j]=dp[i-1][j])
（000） 完全背包问题

---
(115) Distinct Subsequences(hard)
    题目要求在一个字符串S中数有多少个不同的子序列T，状态方程dp[i][j]表示s中的前i个字符与T中的前j个字符子序列的个数，
    如果S[i-1]==T[j-1] 则dp[i][j]=dp[i-1][j] (表示s[i-1]不匹配T[j-1]) + dp[i-1][j-1] （表示s[i-1]匹配T[j-1]）
---
（121） Best Time to Buy andd Sell Stock I
    题目要求只能买卖一次利润最大化，对于每个值，找到之前的最小值，存储他们的差值，然后再次遍历得到差值的最大值
（122） Best Time to Buy andd Sell Stock II
    题目要求可以买无限次，所以，如果num[i]>num[i-1]则res+=num[i]-num[i-1];
（123） Best Time to Buy andd Sell Stock III（hard）
    题目要求只能买卖最多两次，对于每个点，分别求出左区间的最大利润（从前往后遍历，更新最小值），和右区间的最大利润（从后往前遍历，更新最大值），最后在遍历一次取两者之和的最大值
---
(139) Word Break
    题目要求在一个string中查找其是否能由vector中的字符串组成。<br/>
dp的主要思路就是找一个数组存储中间值，然后根据状态方程一步一步推倒，此题状态方程为dp[i]={dp[i-str.size()],dp[0]=true,},遍历每一个vector中的元素找是否满足条件的
---
(152) Maximum Product Subarray
    题目要求在数组中找到一个连续子数组使得子数组内元素乘积最大，考虑负数情况。这题有一个巧妙的方法，O(n)复杂度，用minnumber存储负数最小值，maxnumber存储正数最大值，当遍历过程中是遇到负数，则交换两个值。
---
（221）Maximal Square
    题目要求在一个01矩阵中找到1组成的最大正方形。dp[i][j]表示以matrix[i][j]为右下角的1方阵大小，状态方程dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1 (if(matrix[i][j]='1'))
---
(279) Perfect Squares
    题目要求输入正整数n，输出最少个数可以相加得到n的完全平方数（1,4,9,16）
    首先，要将n以下的完全平方数存在一个数组中square，对于每个i，遍历square
    dp[i]=min(dp[i],dp[i-square[j]]+1) (i>square[j])
---
（300）Longest Increasing Subsequence
    输入没有排序的数组，输出最长递增子序列（子序列可以不连续）。
    dp[i]=max(dp[i],dp[j]+1) (if nums[i]>nums[j])
---
（416） Partition Equal Subset Sum(01背包的变形)
    一个数组是否可以分成两个集合，让这两个集合成员之和相同，dp[i][j]表示前i个数在和为j的情况下是否可以，状态方程和01背包类似
（494）Target Sum
    这道题目经常会有类似的题目，如钟表走指针，需要理解方法并举一反三
8. 排序相关

(147) Insert Sort List
    问题要求在链表中实现插入排序，重点在于链表中要存储一个节点now，但是要判断下一个节点的值才行now->next->val，在判断的时候首先要保证now->next存在
---
(148) Sort List
    问题要求在O(nlogn)时间复杂度下完成链表排序，因为链表快排和堆排序很不方便，只能用归并排序mergesort。
归并排序的思路是递归的将一个链表拆分成两个链表（快慢指针），然后两个链表合并。
    mergesort的时间复杂度都是O(nlogn)，空间复杂度因为有递归，栈也要算，所以空间复杂度为递归的次数O(logn)另外说一下，如果是数组mergesort，在两个数组合并时候要多用一个空间，所以其空间复杂度是O(n)，时间复杂度还是O(nlogn)

9. 其他类型（位运算，二分法，贪心，双指针）

(146) LRU Cache
  这个问题最主要就是考虑好用什么数据结构，一般map+list，map存储键值，list表示顺序，当新插入一个元素用list.push_front()，如果超过capacity则需先list.pop_back()，当要更新位置的时候，则要先list.remove(key)，再list.push_front(key)



