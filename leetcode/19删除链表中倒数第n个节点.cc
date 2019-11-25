/*
 * @Author: haha_giraffe
 * @Date: 2019-11-25 15:02:53
 * @Description: 删除链表中的倒数第n个节点
 */

/* 
    解题思路：链表题，首先要考虑特殊情况，然后快慢指针，快指针先走n步，然后快慢指针一起走
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return nullptr;
        }
        if(!head->next){
            if(n==1){
                return nullptr;
            }
            else{
                return head;
            }
        }
        ListNode* f = head;
        ListNode* s = head;
        int tmp = n;
        while(tmp--){
            f= f->next;
        }
        while(f && f->next!=nullptr){
            f= f->next;
            s= s->next;
        }
        if(f==nullptr){
            return head->next;
        }
        s->next = s->next->next;
        return head;
    }
};