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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> rev;
        ListNode* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        temp = head;
        ListNode *thead = new ListNode(0);
        ListNode *ans = thead;
        while(count>=k){
            int tempK = k;
            while(tempK){
                rev.push(temp);
                temp = temp->next;
                tempK--;
            }
            // thead->next = rev.top();
            // rev.pop();
            // thead = thead->next;
            while(!rev.empty()){
                thead->next = rev.top();
                rev.pop();
                thead = thead->next;
            }
            count -= k;
        }
        thead->next = temp;
        return ans->next;
    }
};