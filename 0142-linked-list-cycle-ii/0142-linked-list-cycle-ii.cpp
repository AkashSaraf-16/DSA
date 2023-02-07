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
        if(!head)
            return NULL;
        if(head==head->next)
            return head;
        unordered_map<ListNode*,ListNode*> mp;
        ListNode* thead=new ListNode(-1);
        thead->next=head;
        ListNode* temp=thead;
        while(temp){
            if(temp==temp->next)
                return temp;
            if(mp.find(temp->next)!=mp.end()){
                return mp[temp->next->next];
            }
            mp[temp->next]=temp;
            temp=temp->next;
        }
        return NULL;
    }
};