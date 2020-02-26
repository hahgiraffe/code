/*
 * @Author: haha_giraffe
 * @Date: 2020-02-20 11:36:07
 * @Description: 反转链表
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        ListNode* node = head;
        ListNode* next = head->next;
        head->next = NULL;
        while(next){
            ListNode* tmp = next->next;
            next->next = node;
            node = next;
            next = tmp;
        }
        return node;
    }
};