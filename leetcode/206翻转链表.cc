/*
 * @Author: haha_giraffe
 * @Date: 2020-01-02 20:21:43
 * @Description: 翻转链表
 */

/* 
    解题思路：这道题思路很简单，就是三指针，但是做了好多次都没有把递归和迭代的两种想法完全写出
*/

class Solution {
public:
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* prev = NULL;
    //     ListNode* cur = head;
    //     ListNode* next = NULL;
    //     while(cur){
    //         next = cur->next;
    //         cur->next = prev;
    //         prev = cur;
    //         cur = next;   
    //     }
    //     return prev;
    // }
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* tmp = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return tmp;
    }
};