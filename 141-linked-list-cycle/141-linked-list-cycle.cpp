/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
     // while(head != NULL){
     //     if(head->val == -100000){
     //         return true;
     //     }
     //     head->val = -100000;
     //     head = head->next;
     // }  
     //    return false;
        if(!head || !head->next) return false;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};