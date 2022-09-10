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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> mp;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        int sum =0;
        while(curr){
            sum+= curr->val;
            if(mp.find(sum) != mp.end()){   // we will get this only when either curr->val is 0/less than 0
                curr = mp[sum]->next;            
                int temp_sum = sum+curr->val;   // we are adding in temp_sum becoz from this point until we get temp_sum == sum there are  nodes whose sum will result in 0 
                while(temp_sum != sum){        
                    mp.erase(temp_sum);       
                    curr = curr->next;
                    temp_sum += curr->val;
                }
                mp[sum]->next = curr->next;
            }
            else{
                mp[sum] = curr;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};