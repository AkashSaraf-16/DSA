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
    // RECURSIVE APPROACH 1:
    /*
    ListNode* helper(ListNode* head){
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *rHead = helper(head->next);
        ListNode *rTail = head->next;
        rTail->next = head;
        head->next = NULL;
        
        return rHead;
    }
    ListNode* reverseList(ListNode* head) {
        return helper(head);
    }
    */
    // RECURSIVE APPROACH 2:
    /*
    ListNode *reverseHelper(ListNode *head){

        if(head->next == nullptr)  {    // base condition
            return head;     
        } 

        // hypothesis
        ListNode *temp = head;
        head = head->next;
        ListNode *temp2 = reverseHelper(head);
        // induction
        while(head->next != nullptr){
            head = head->next;
        }
            head->next = temp;
            temp->next = nullptr;
            return temp2;

    }
    */
    ListNode* reverseList(ListNode* head) {
    // ITERATIVE
        if(!head)   return head;

        ListNode *curr = head;
        ListNode *prev = NULL;
        while(curr){
            ListNode *n=curr->next;
            curr->next = prev;
            prev = curr; 
            curr = n;          
        } 
        
        return prev;
       // return reverseHelper(head);   
    }
};