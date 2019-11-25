/*
 * @Author: haha_giraffe
 * @Date: 2019-11-25 16:02:49
 * @Description: 合并k个排序链表
 */

/* 
    解题思路：遍历一遍链表两两merge即可
*/
class Solution {
public:
    ListNode* merge2List(ListNode* l,ListNode* r){
        if(!l){
            return r;
        }
        if(!r){
            return l;
        }
        ListNode* res = new ListNode(0);
        ListNode* head = res;
        while(l && r){
            if(l->val < r->val){
                res->next = l;
                l=l->next;
            }
            else{
                res->next = r;
                r=r->next;
            }
            res = res->next;
        }
        if(l){
            res->next = l;
        }
        if(r){
            res->next = r;
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        int n = lists.size();
        if(n==1){
            return lists[0];
        }
        int i=1;
        ListNode* l = lists[0];;
        while(i<n){
            ListNode* r = lists[i];
            l=merge2List(l,r);
            i++;
        }
        return l;
    }
};