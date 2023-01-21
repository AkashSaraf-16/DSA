/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* t=head;
        while(t && t->val==val){
            t=t->next;
        }
        ListNode* res=t;
        while(t&&t->next){
            if(t->next->val==val)
                t->next=t->next->next;
            else
                t=t->next;
        }
        return res;
    }
};