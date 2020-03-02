/*
 * @Author: haha_giraffe
 * @Date: 2020-03-02 14:53:41
 * @Description: 输入两个链表，找出它们的第一个公共节点。
 */
class Solution {
public:
    int getlen(ListNode* headA){
        ListNode* tmp = headA;
        int len = 0;
        while(tmp){
            tmp = tmp->next;
            len++;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = getlen(headA);
        int len2 = getlen(headB);
        int dif = 0;
        if(len1 > len2){
            dif = len1 - len2;
            while(dif--){
                headA = headA->next;
            }
        }
        if(len1 < len2){
            dif = len2 - len1;
            while(dif--){
                headB = headB->next;
            }
        }
        while(headA && headB){
            if(headA == headB){
                return headA;
            } else {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL;
    }
};