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
    void reorderList(ListNode* head) {
        // Approach 1 : TC:O(N^2) SC:O(1)
        // ListNode* start = head;
        // while(start && start->next && start->next->next){
        //     ListNode* end1 = start;
        //     while(end1->next->next){
        //         end1 = end1->next;
        //     }
        //     ListNode* end2 = end1->next;
        //     end1->next = NULL;
        //     end2->next = start->next;
        //     start->next = end2;
        //     start = start->next->next;
        // }
        // Approach 2 : TC:O(N) SC:O(N)
        stack<ListNode*> s;
        ListNode* temp = head;
        int len = 0;
        while(temp){
            len++;
            s.push(temp);
            temp = temp->next;
        }
        temp = head;
        for(int j = 0 ; j < len/2 ; j++){
            ListNode* end = s.top();
            s.pop();
            end->next = temp->next;
            temp->next = end;
            temp = temp->next->next;
        }
        temp->next = NULL;
    }
};