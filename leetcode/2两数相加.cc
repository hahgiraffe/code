/*
 * @Author: haha_giraffe
 * @Date: 2019-10-24 20:51:18
 * @Description: 两个非空链表，相加节点中的每一位
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 */


/* 
    解题思路：这个就是双指针移动相加，注意进位就好（如果反过来的话，就要先链表翻转）
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        int add = 0;
        int sum = 0;
        ListNode* head = new ListNode(0);
        ListNode* res = head;
        while(tmp1 && tmp2){
            sum = (tmp1->val + tmp2->val + add)%10;
            ListNode* newnode = new ListNode(sum);
            res->next = newnode;
            res = res->next;
            add = (tmp1->val + tmp2->val + add)/10;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        while(tmp1){
            sum = (tmp1->val + add)%10;
            ListNode* newnode = new ListNode(sum);
            res->next = newnode;
            res = res->next;
            add = (tmp1->val + add)/10;
            tmp1 = tmp1->next;
        }
        while(tmp2){
            sum = (tmp2->val + add)%10;
            ListNode* newnode = new ListNode(sum);
            res->next = newnode;
            res = res->next;
            add = (tmp2->val + add)/10;
            tmp2 = tmp2->next;
        }
        if(add){
            ListNode* newnode = new ListNode(1);
            res->next = newnode;
            res = res->next;
        }
        return head->next;
    }
};