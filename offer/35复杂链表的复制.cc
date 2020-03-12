/*
 * @Author: haha_giraffe
 * @Date: 2020-03-09 14:56:10
 * @Description: 
    请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
 */

/* 
    解题思路：用一个unordered_map<Node*,Node*>实现，先简历每个节点的对应关系，然后如果该节点有next或random，则在对应map中，增加
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        unordered_map<Node* , Node*> m;
        for(Node* n = head; n; n = n ->next){
            m[n] = new Node(n->val);
        }
        for(Node* n = head; n; n = n->next){
            if(n->next) m[n]->next = m[n->next];
            if(n->random) m[n]->random = m[n->random];
        }
        return m[head];
    }
};