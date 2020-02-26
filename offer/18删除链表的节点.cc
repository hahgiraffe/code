/*
 * @Author: haha_giraffe
 * @Date: 2020-02-18 23:59:51
 * @Description: 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。返回删除后的链表的头节点。
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head || (!head->next && head->val == val)){
            return NULL;
        }
        if(head->val == val){
            return head->next;
        }
        ListNode* next = head->next;
        ListNode* now = head;
        while(next){
            if(next->val == val){
                now->next = now->next->next;
                break;
            }
            now = now->next;
            next = next->next;
        }
        return head;
    }
};