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
    ListNode *detectCycle(ListNode *head) {
        // TC:O(N) SC:O(N)
        /*if(!head)               // edge case if no node
            return NULL;
        if(head == head->next)      // edge case if 1 node with loop
            return head;
        unordered_map<ListNode*,ListNode*> mp;  // in key we are storing next pointer as we want unique value and invalue we are storing the node 
        ListNode* thead = new ListNode(-1);     // to handle case when tail points to head
        thead->next = head;
        ListNode* temp = thead ;
        while(temp){
            if(temp == temp->next)          // edge case when tail points to itself
                return temp;
            if(mp.find(temp->next) != mp.end()){        // normal cases
                return mp[temp->next->next];
            }
            mp[temp->next] = temp;
            temp = temp->next;
        }
        return NULL;
        */
        // OPTIMAL: TC:O(N) SC:O(1)
            if(!head || !head->next){
                return NULL;
            }
            ListNode* fast = head;
            ListNode* slow = head;
            ListNode* entry = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                while(slow != entry){
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};