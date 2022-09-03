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
   /* // Brute force
    ListNode *curr = head;
    if(!head)   return head;
    while(curr->next != nullptr){
        ListNode *temp = curr->next;
        while(temp->next != nullptr && temp->val == curr->val){
            temp = temp->next;
        }
        if(temp->next == nullptr && temp->val == curr->val){
            curr->next = nullptr;
            break;
        }
        curr->next = temp;
        curr = curr->next;
    } */  
        ListNode *curr = head;
        ListNode *prev = nullptr;
        if(!head)   return head;
        while(curr){
            if(prev!= nullptr && prev->val == curr->val){
                prev->next = curr->next ;
                curr = curr->next;
            }else{
                prev = curr;        
                curr = curr->next;  
            }
        }
        return head;
    }
};