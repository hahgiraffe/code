/*
 * @Author: haha_giraffe
 * @Date: 2020-02-20 11:29:54
 * @Description: 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
 * 例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。
 */
/* 
    解题思路：也是快慢指针，快指针先走k-1步，同时还要考虑k是否小于链表长度
*/
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(!head) return head;
        ListNode* f = head;
        ListNode* s = head;
        while(--k && f){
            f = f->next;
        }
        if(!f){
            return NULL;
        }
        while(f->next){
            f = f->next;
            s = s->next;
        }
        return s;
    }
};