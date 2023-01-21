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
    ListNode* helper(ListNode* head){
        if(!head || !head->next)
            return head;
        ListNode* rHead=helper(head->next);
        ListNode* rTail=head->next;
        rTail->next=head;
        head->next=NULL;
        return rHead;
    }
    ListNode* reverseList(ListNode* head) {
        return helper(head);
    }
};