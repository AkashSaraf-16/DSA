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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        if(!head->next->next){
            return head->val==head->next->val;    
        }
        ListNode *slow=head,*fast=head,*slowPrev=NULL;
        // Finding the middle
        while(fast->next && fast->next->next){
            slowPrev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        // Dividing the list in two parts
        ListNode *l1,*l2;
        if(fast->next){
            l1=slow;
            l2=slow->next;
        }else{
            l1=slowPrev;
            l2=slow->next;
        }
        ListNode *curr=head,*prev=NULL;
        // Reversing the first part
        while(curr!=l2){
            ListNode* n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        // Checking pallindrome
        while(l1&&l2){
            if(l1->val!=l2->val)
                return false;
            l1=l1->next;
            l2=l2->next;
        }
        return true;
    }
};