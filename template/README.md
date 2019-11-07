<!--
 * @Author: haha_giraffe
 * @Date: 2019-11-06 22:54:53
 * @Description: 
 -->
# 这一个文件夹中记录一些经典题解的模板！十分重要！
## 二分查找模板
二分查找的题目变化很多(标准二分查找，二分查找左节点，二分查找右节点)，而且有许多不同的变种，很需要多次讨论。可以用二分查找的条件：首先要有一个排序的区间，然后目的是在区间中查找一个值。参考[博客](https://segmentfault.com/a/1190000016825704)
### 标准的二分查找
leetcode 704，374，69 基本上都是标准二分查找的变形
```cpp
class Solution {
public:
    int search(vector< int >& nums, int target) {
        if(nums.empty()){
            return -1;
        }
        int l=0;                        //注意这里的l和r都要是在区间内，可能被查找到的值
        int r=nums.size()-1;
        while(l<=r){                    //注意这里有等号
            int middle=l+((r-l)>>1);    //注意这里有优先级的问题啊，如果要用>>必须加括号
            // int middle=l+(r-l)/2;
            if(nums[middle]==target){
                return middle;
            }
            else if(nums[middle] < target){
                l=middle+1;
            }
            else{
                r=middle-1;
            }
        }
        return -1;
    }
};
```
### 二分查找左边界
当数组有序且数组中的元素有可能重复。这时候就要注意一个思想，就是当找到num[middle]==target时候不一定就是左端点，但是如果找到num[middle] < targe的时候,一定不是左端点。
leetcode 278,744(这个应该是找右端点upperbound),153
```cpp
class Solution {
public:
    int search(vector< int >& nums, int target) {
        if(nums.empty()){
            return -1;
        }
        int l=0;                        //注意这里的l和r都要是在区间内，可能被查找到的值
        int r=nums.size()-1;
        while(l< r){                    //注意这里没有等号
            int middle=l+((r-l)>>1);    //注意这里有优先级的问题啊，如果要用>>必须加括号
            if(nums[middle] < target){  //这里只考虑
                l=middle+1;
            }
            else{
                r=middle;
            }
        }
        return nums[l]==target ? l : -1;
    }
};
```
### 二分查找右边界


## kmp经典模板