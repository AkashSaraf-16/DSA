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
        // ListNode* curr=head;
        // while(curr && curr->next && curr->next->next){
        //     ListNode* end1=head;
        //     while(end1->next->next){
        //         end1=end1->next;
        //     }
        //     ListNode* end2=end1->next;
        //     end1->next=NULL;
        //     end2->next=curr->next;
        //     curr->next=end2;
        //     curr=curr->next->next;
        // }
        stack<ListNode*> s;
        ListNode* curr=head;
        int count=0;
        while(curr){
            count++;
            s.push(curr);
            curr=curr->next;
        }
        curr=head;
        ListNode* end;
        for(int i=0;i<count/2;i++){
            end=s.top();
            s.pop();
            end->next=curr->next;
            curr->next=end;
            curr=curr->next->next;
        }
        curr->next=NULL;
    }
};