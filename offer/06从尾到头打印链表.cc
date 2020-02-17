/*
 * @Author: haha_giraffe
 * @Date: 2020-02-15 20:31:23
 * @Description: 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）
 */

/* 
    解题思路：就是反转链表，然后打印即可。注意一开始要把head->next置为空，否则反向遍历的时候循环不会停
*/
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if(!head) return {};
        ListNode* l = head;
        ListNode* n = head->next;
        head->next = NULL;
        while(n){
            ListNode* tmp = n->next;
            n->next = l;
            l = n;
            n = tmp;
        }
        vector<int> res;
        while(l){
            res.push_back(l->val);
            l = l->next;
        }
        return res;
    }
};