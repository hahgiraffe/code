/*
 * @Author: haha_giraffe
 * @Date: 2020-01-08 21:33:44
 * @Description: 回文链表（要求事件复杂度O(n), 空间复杂度O(1)）
 */
/* 
    解题思路：首先找到链表中点，然后断开，分成两个链表，翻转后一个链表即可
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //首先找到中间节点
        if(!head || !head->next) return true;
        ListNode* s = head;
        ListNode* f = head;
        ListNode* last = head;
        while(f && f->next){
            f = f->next->next;
            last = s;
            s = s->next;
        }
        //这里注意切断last与s之间的连接，使其称为两个独立的链表，反转第二个链表即可
        last->next = NULL;
        ListNode* prev = NULL;
        ListNode* cur = s;
        ListNode* next;
        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        ListNode* l1 = head;
        ListNode* l2 = prev;
        while(l1 && l2){
            if(l1->val != l2->val) return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;

    }
};