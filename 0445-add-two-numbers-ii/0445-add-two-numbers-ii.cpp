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
    /*
    ListNode* Rev(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = Rev(l1);
        l2 = Rev(l2);
        ListNode* prev = NULL;
        ListNode* res = NULL;
        ListNode* temp = NULL;
        int digit,carry = 0;
        while(l1 != NULL || l2 !=NULL){
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            digit = sum%10;
            carry = sum/10;
            temp = new ListNode(digit);
            if(res == NULL)     // to store the head of resultant LL
                res = temp;
            else
                prev->next = temp;
            prev = temp;
            if(l1) l1 = l1->next ; 
            if(l2) l2 = l2->next ; 
        }
        if(carry){
           temp->next = new ListNode(carry);
        }
        return Rev(res);
    }
};
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2=l2->next;
        }
        int sum = 0;
        ListNode* head = new ListNode(0);
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()) {
                sum+= s1.top();   
                s1.pop();
            }
            if(!s2.empty()){
                sum+= s2.top();   
                s2.pop();
            }
            head->val = sum%10;
            ListNode* temp = new ListNode(sum/10);
            temp->next = head;
            head = temp;
            sum/= 10;
        }
        return head->val == 0 ? head->next : head;
    }
};