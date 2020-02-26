/*
 * @Author: haha_giraffe
 * @Date: 2020-02-20 11:42:05
 * @Description: 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dump = new ListNode(0);
        ListNode* head = dump;
        while(l1 && l2){
            if(l1->val < l2->val){
                dump->next = l1;
                l1 = l1->next;
            }
            else{
                dump->next = l2;
                l2 = l2->next;
            }
            dump = dump->next;
        }
        if(l1){
            dump->next = l1;
        }
        else{
            dump->next = l2;
        }
        return head->next;
    }
};