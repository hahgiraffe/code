<!--
 * @Description: leetcode刷题记录
 * @Author: haha_giraffe
 * @Date: 2019-08-14 10:12:35
 -->
# leetcode 刷题记录
    本笔记用于记录leetcode刷题的想法，用于总结和回顾，根据类型进行分，相同类型依照题号排列
## 数组
### 连续子数组等于一个target
    如果数组中的数字都为正数，则可以用双指针滑动窗口方法（当sum<target，右指针右移，当sum>target，左指针右移）
    如果数组中的数字存在负数，则要用前缀和，presum[i]表示数组中i及i之前的数字的和，直接算则需要O(n2),除此之外可用一个map存储每个i及其其presum，这样O(n)即可，遍历数组求sum，然后在map中查找sum-target是否存在，如果存在则说明有一个解。
### （347）Top k Frequent Elements
    在一个数组中找到出现次数最多的k个数。用到map+heap(priority_queue)
### (378. Kth Smallest Element in a Sorted Matrix)
    在一个n*n的数组中，每行每列都是递增序列，找到第k小的元素。
    这道题目有多种方法，最容易想到的就是priority_queue,但是没有利用题中的条件，性能也不高
    最好的方法是利用值域二分查找，在matrix[0][0]和matrix[n-1][n-1]中进行二分，得到middle，再在矩阵中查找比middle小的元素个数count，将count与k进行比较
## 二叉树
### （236） Lowest Common Ancestor of a Binary Tree（重要）
    这道题用的是最简单的后序遍历dfs，递归返回TreeNode*,如果找到则返回，如果没有找到返回NULL
  ```cpp
      TreeNode* dfs(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root){
            return NULL;
        }
        if(root==p || root==q){
            return root;
        }
        TreeNode* l=dfs(root->left,p,q);
        TreeNode* r=dfs(root->right,p,q);
        if(l && r){
            return root;
        }
        else if(l){
            return l;
        }
        else if(r){
            return;Verify Preorder Serialization of a Binary Tree
        }
        else{
            return NULL;
        }
    }
```
### （331）Verify Preorder Serialization of a Binary Tree
    这道题目给一个序列，判断是否是二叉树的前序遍历（题目指定不能用建树的方法），那就只能用一个办法来判断数字和#的位置、数量是否合理
    用一个count表示二叉树中的空余位置，初始化为1，遍历整个string，当每次遇到’，‘，则前一个占用一个空位，空位数目-1，如果是前一个字符是数字则空位数目加2，如果前一个是#则空位不变，
    每次还要判断count<0则输出结果false，最后如果count==0则正确
## 字符串
### （131） Palindrome Partitioning
    给定一个字符串，分割其每个子串为一个回文字符串。回溯法暴力搜索，从头往后遍历字符串，如果找到一个是回文，则dfs继续后面的，注意substr是[begin,end)

### （132） Palindrome Partitioning II
    求能分割成的子回文字符串，最少切的刀数，如果按照131的方法会超时，所以只能用两个dp，第一个dp[i][j]判断字符串str(i,j)是否为回文，dp[i][j]=(s[i]==s[j]) && dp[i+1]dp[j-1]
    第二个dp f[n]表示前n个字符中，最少可以分割几个回文子串 如果dp[k][n-1]是回文，则f[n]=max(f[n],f[n-k]+1)
### （241） Different Ways to Add Parentheses
    给定一个字符串，求在不同的地方添加括号，输出所有不同的解。最常用的方法就是dfs，对于每一个符号都进行左右分别递归，分别求出两边所有可能的数字结果，然后每两个进行运算，结果放在数组中返回
### （179） Largest Number
    将一组整数组成最大的数，首先要将int转换成string，然后sort，根据每两个string比较，连接后是否更大

## 链表

### (82)/(83) Remove Duplicates from Sorted List
    在排序好的链表中删除重复的数字，82是保留一个，83是重复数字不保留,基本思路都是双指针，83再加一个set用来存储重复的数字即可，然后再遍历一遍删除即可。
### （234）Palindrome Linked List
    判断一个链表是否是回文，思路要发生转变，判断一个回文不一定要从中间节点往两边遍历，这样对于数组是可行的，但是链表不行，所以正确的思路是要先找到链表总长度，然后一半就是中间节点，然后将后面的链表翻转，在顺序遍历前后两个链表

## 哈希表

## DFS
### (51) / (52) N-Queens
    N皇后是非常经典的题目，题目要求在棋盘上放置皇后，横竖斜都不相邻，主要思想是dfs，用一个vector arr存储第n行的皇后位于arr[n]列，递归返回条件是arr.size() == n ,如果满足条件则找到一个，如果没有达到条件则继续尝试。
## 动态规划（DP）
### （000） 01背包问题
    有n个背包，每个背包有weight和value，且只能选一次在给定的W下，求最大的V，dp[i][j]表示在前i个物品背包容量j的情况下最大的价值,每个背包有两个状态，取或者不取
    状态方程 dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);(当j>weight[i]时，如果小于直接dp[i][j]=dp[i-1][j])
### （000） 完全背包问题
### (115) Distinct Subsequences(hard)
    题目要求在一个字符串S中数有多少个不同的子序列T，状态方程dp[i][j]表示s中的前i个字符与T中的前j个字符子序列的个数，
    如果S[i-1]==T[j-1] 则dp[i][j]=dp[i-1][j] (表示s[i-1]不匹配T[j-1]) + dp[i-1][j-1] （表示s[i-1]匹配T[j-1]）
### （121） Best Time to Buy andd Sell Stock I
    题目要求只能买卖一次利润最大化，对于每个值，找到之前的最小值，存储他们的差值，然后再次遍历得到差值的最大值
### （122） Best Time to Buy andd Sell Stock II
    题目要求可以买无限次，所以，如果num[i]>num[i-1]则res+=num[i]-num[i-1];
### （123） Best Time to Buy andd Sell Stock III（hard）
    题目要求只能买卖最多两次，对于每个点，分别求出左区间的最大利润（从前往后遍历，更新最小值），和右区间的最大利润（从后往前遍历，更新最大值），最后在遍历一次取两者之和的最大值
### (139) Word Break
    题目要求在一个string中查找其是否能由vector中的字符串组成。
    dp的主要思路就是找一个数组存储中间值，然后根据状态方程一步一步推倒，此题状态方程为dp[i]={dp[i-str.size()],dp[0]=true,},遍历每一个vector中的元素找是否满足条件的
### (152) Maximum Product Subarray
    题目要求在数组中找到一个连续子数组使得子数组内元素乘积最大，考虑负数情况。这题有一个巧妙的方法，O(n)复杂度，用minnumber存储负数最小值，maxnumber存储正数最大值，当遍历过程中是遇到负数，则交换两个值。
### （221）Maximal Square
    题目要求在一个01矩阵中找到1组成的最大正方形。dp[i][j]表示以matrix[i][j]为右下角的1方阵大小，状态方程dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1 (if(matrix[i][j]='1'))
### (279) Perfect Squares
    题目要求输入正整数n，输出最少个数可以相加得到n的完全平方数（1,4,9,16）
    首先，要将n以下的完全平方数存在一个数组中square，对于每个i，遍历square
    dp[i]=min(dp[i],dp[i-square[j]]+1) (i>square[j])
### （300）Longest Increasing Subsequence
    输入没有排序的数组，输出最长递增子序列（子序列可以不连续）。
    dp[i]=max(dp[i],dp[j]+1) (if nums[i]>nums[j])
### （416） Partition Equal Subset Sum(01背包的变形)
    一个数组是否可以分成两个集合，让这两个集合成员之和相同，dp[i][j]表示前i个数在和为j的情况下是否可以，状态方程和01背包类似
### （494）Target Sum
    这道题目经常会有类似的题目，如钟表走指针，需要理解方法并举一反三
### （312）Burst Balloons
    一个连续的数组，戳爆一个气球，可以得分是相邻三个数乘积，求最大乘积和
    dp思路，难点在于状态方程和遍历时候的方法，要先按照len从1到n
## 排序相关

### (147) Insert Sort List
    问题要求在链表中实现插入排序，重点在于链表中要存储一个节点now，但是要判断下一个节点的值才行now->next->val，在判断的时候首先要保证now->next存在
### (148) Sort List
    问题要求在O(nlogn)时间复杂度下完成链表排序，因为链表快排和堆排序很不方便，只能用归并排序mergesort。归并排序的思路是递归的将一个链表拆分成两个链表（快慢指针），然后两个链表合并。
    mergesort的时间复杂度都是O(nlogn)，空间复杂度因为有递归，栈也要算，所以空间复杂度为递归的次数O(logn)另外说一下，如果是数组mergesort，在两个数组合并时候要多用一个空间，所以其空间复杂度是O(n)，时间复杂度还是O(nlogn)

## 其他类型（位运算，二分法，贪心，双指针，图）
### (146) LRU Cache
    这个问题最主要就是考虑好用什么数据结构，一般map+list，map存储键值，list表示顺序，当新插入一个元素用list.push_front()，如果超过capacity则需先list.pop_back()，当要更新位置的时候，则要先list.remove(key)，再list.push_front(key)
### （153）、（154） Find Minimum in Rotated Sorted Array
    二分解决，但是要注意low与middle之间比大小时候的等于的情况（在有重复节点的时候）
### （190） Reverse Bits
    将一个32位整数每位翻转,首先要知道怎么获取每一位的数值，用的是num>>i & 1 (i是位数)，然后将获取到的每位数值加到结果中，并循环32次，每次往左移动一位
### （201） Bitwise AND of Numbers
    将[m,n]范围内的数字按位与并求结果。思路就是，从高位到低位遍历，若第k位m和b不一样，则结果的[k,0]都为0
### （209）Minimum Size Subarray Sum
    在一个数组中，找到连续子数组的值>=s，求连续子数组最小长度，这题看似dp，其实用双指针（滑动窗口）可以O(n)，当窗口内值小于s，窗口加右指针值，右指针++，当窗口内值大于等于s，窗口减左指针值，左指针++
### （318） Maximum Product of Word Lengths
    给一个字符串数组，返回两个最大字符串长的乘机，这两个字符串中字符都不相同，可以用位运算来做
    主要过程判断两个字符串中字符是否不同,得到的val[i]表示words[i]中有哪几个字符，如果有'a'则val[i]的第0位置一，以此类推，最后在遍历数组判断val[i] & val[j]是否等于0，如果等于0表示亮哥哥字符串中没有一个字符相同
  ```cpp
    vector<int> val(words.size());
    for (int i = 0; i < words.size(); i++)
        for (auto &c : words[i])
            val[i] |= 1 << (c - 'a');
  ```

### （4）Median of Two Sorted Arrays（系列，两个或多个有序数组找中位数！！很重要）
### （207）（210） Course Schedule
    拓扑排序，给定课程的数量和每个课程及其前缀课程，判断是否能上完所有的课程。方法就是拓扑排序，用一个一维数组存储每个节点的入度，一个二维数组存储每个节点及其后续课程，用一个栈把入度为0的节点放进去
### （208）字典树
    每个节点为一个字符，从根节点开始往下找可以找到一个字符串，常用于字符串的查找，插入，判断字符串前缀，都为O(m),m为字符串的字符个数
### （134）Gas Station
    贪心法，加油站，要搞清楚两个结论（1）如果所有油量总和大于油量消耗，则一定有解（2）如果从i-j加起来油量总和<油量消耗，则i-j中的任意一个点都不能为起始点
### （316）Remove Duplicate Letters
    删除一个字符串的重复字符，并返回最小的字典序，贪心+string，核心思想就是遍历字符串，将字符与结果末尾字符进行对比，如果比其小并且结果末尾字符在后续还有，则弹出结果末位字符，
    同时要用一个数组记录每个出现字符个数，另一个数组记录结果是否有该字符