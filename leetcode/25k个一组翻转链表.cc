/*
 * @Author: haha_giraffe
 * @Date: 2020-03-15 10:43:32
 * @Description: k个一组翻转链表
    给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 */

/* 
    解题思路：只要考虑指针的用法，链表翻转和之前的是一样的，但是要找到节点之间的转移关系。好好思考
*/
class Solution {
public:
    ListNode* reverse(ListNode* l){
        if(!l || !l->next){
            return l;
        }
        ListNode* tmp = l->next;
        l->next = NULL;
        ListNode* head = l;
        while(tmp){
            ListNode* t = tmp->next;
            tmp->next = head;
            head = tmp;
            tmp = t;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dump = new ListNode(0);
        dump->next = head;
        ListNode* pre = dump;
        ListNode* end = dump;
        while(end->next){
            for(int i = 0; i < k && end != NULL; ++i){
                end = end->next;
            }
            if(end == NULL){
                break;
            }
            ListNode* start = pre->next;
            ListNode* next = end->next;
            end->next = NULL;
            // printf("   %d\n", start->val);
            pre->next = reverse(start);
            // printf("%d\n", pre->next->val);
            start->next = next;
            pre = start;
            end = pre;
        }
        
        return dump->next;
    }
};