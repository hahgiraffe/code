/*
 * @Author: haha_giraffe
 * @Date: 2020-01-03 20:00:24
 * @Description: 链表排序
 */

/* 
    链表排序：
*/

class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val < l2->val){
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else{
            l2->next = merge(l2->next, l1);
            return l2;
        }
    }
    
    ListNode* mergesort(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        //快慢指针
        ListNode* f = head;
        ListNode* s = head;
        ListNode* tar = head;
        while(f && f->next){
            f = f->next->next;
            tar = s;
            s = s->next;
        }
        tar->next = nullptr;   //把前一个指针断掉
        ListNode* l1 = mergesort(head);
        ListNode* l2 = mergesort(s);
        return merge(l1, l2);
    }
    
    ListNode* sortList(ListNode* head) {
        //O(nlogn)时间复杂度 + O(1)空间复杂度 数组归排空间复杂度为O(n)，链表归排就可以到O(1)
        //首先要想一个问题，如果递归调用的话，空间复杂度会为O(logn)了，意味着普通的mergesort就不行了
        //先掌握递归方法，再去看迭代排序
        return mergesort(head);
    }
};