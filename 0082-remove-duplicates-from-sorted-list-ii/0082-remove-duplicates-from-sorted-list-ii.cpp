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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* sentinel = new ListNode(0,head);
        ListNode* pred = sentinel;// predecessor = the last node 
                                  // before the sublist of duplicates
        while(head){
            // if same values encountered
            if(head->next && head->val == head->next->val){
                while(head->next && head->val == head->next->val){
                    head=head->next;
                }
                // make new connection with pred to part which is not repeating
                pred->next = head->next; 
            }
            else{
                pred = pred->next;
            }
            head = head->next;
        }
        return sentinel->next;
    }
};