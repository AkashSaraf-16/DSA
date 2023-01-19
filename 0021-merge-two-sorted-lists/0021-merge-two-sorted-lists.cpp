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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res=new ListNode(-101);
        ListNode* t,*l1=list1,*l2=list2;
        t=res;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<list2->val){
                t->next=list1;
                list1=list1->next;
            }
            else{
                t->next=list2;
                list2=list2->next;
            }
            t=t->next;
        }
        while(list1){
            t->next=list1;
            list1=list1->next;
            t=t->next;
        }
        while(list2){
            t->next=list2;
            list2=list2->next;
            t=t->next;
        }
        t->next=nullptr;
        return res->next;
    }
};