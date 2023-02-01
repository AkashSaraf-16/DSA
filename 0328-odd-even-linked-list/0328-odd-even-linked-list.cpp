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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return head;
        else{
            ListNode *oddH=head,*oddT=head,*evenH=head->next,*evenT=head->next;
            while(evenT&&evenT->next){
                oddT->next=oddT->next->next;
                evenT->next=evenT->next->next;
                oddT=oddT->next;
                evenT=evenT->next;
            }
            oddT->next=evenH;
            return oddH;
        }
    }
};