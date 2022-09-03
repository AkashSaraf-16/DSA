//RECURSIVE APPROACH
/*
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        head->next = removeElements(head->next,val);
        return head->val == val ? head->next : head;
    }
};
*/
// SENTINEL NODE
/*
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    ListNode *curr = head;
    ListNode *prev = NULL;
    while(curr!= NULL){
        if(curr->val == val){
            if(prev == NULL){
                head = head->next;
                delete curr;
                curr = head;
            }else{
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
        return head;
    }
};
*/
// ONE POINTER APPROACH
class Solution {
public:
    // one pointer approach
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return head;
		// This is for the case when a linked list is like this: 
		// 1->1->2->null , val = 1
		// 1->1->1->null , val = 1
        while(head!=nullptr && head->val==val){
            head = head->next;
        }
        ListNode* curr = head;
        while(curr!=nullptr  && curr->next!=nullptr){
            if(curr->next->val==val){
                curr->next = curr->next->next;
				// After doing the above step, I am not updating "curr" because of these type of test cases:
				// 1->2->3->6->6->6->5->null  val = 6
            }
            else
                curr = curr->next;
        }
        return head;
    }
};
