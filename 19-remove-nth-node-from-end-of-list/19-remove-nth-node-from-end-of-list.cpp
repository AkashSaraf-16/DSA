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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast,*slow;
        fast = head;
        slow = head;
        while(n>0 || fast->next){
            if(n){      // moving fast pointer by n moves 
                fast = fast->next;
                n--;
            }
            if(!fast)   // when we delete nth node from end and total no. of nodes are also n
                return slow->next;
            if(!n && fast->next){     // if we have made a diff of n b/w slow and fast pointers
                slow = slow->next;
                fast = fast->next;
            }
        }
        slow->next = slow->next->next;
        return head;
    }
};