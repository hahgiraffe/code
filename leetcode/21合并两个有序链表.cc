/*
 * @Author: haha_giraffe
 * @Date: 2019-11-25 15:15:21
 * @Description: 合并两个有序链表
 */

/*
    解题思路；用指针替换即可，小技巧就是可以申请一个头结点，然后就可以直接比较两个链表的第一个节点
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* f = l1;
        ListNode* s = l2;
        if(!f){
            return s;
        }
        if(!s){
            return f;
        }
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;
        while(f && s){
            if(f->val < s->val){
                tmp->next = f;
                f = f->next;
            }
            else{
                tmp->next = s;
                s = s->next;
            }
            tmp = tmp->next;
        }
        if(f){
            tmp->next = f;  
        }
        if(s){
            tmp->next = s;
        }
        return head->next;
        
    }
};