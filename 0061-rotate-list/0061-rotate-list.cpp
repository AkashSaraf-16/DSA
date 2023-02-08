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
    ListNode* getSecLast(ListNode* head){
        ListNode* curr = head;
        while(curr->next->next){
            curr = curr->next;
        }
        return curr;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        ListNode* curr = head;
        int count = 0 ;
        while(curr){
            count++;
            curr = curr->next;
        }
        for(int i = 1 ; i<= k%count ; i++){
            ListNode* sec_last = getSecLast(head);
            ListNode* last = sec_last->next;
            sec_last->next = NULL;
            last->next = head;
            head = last;
        }
        return head;
    }
};