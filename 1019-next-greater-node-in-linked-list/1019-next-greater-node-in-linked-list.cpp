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
    vector<int> nextLargerNodes(ListNode* head) {
        // vector<int> v;
        // while(temp){
        //     v.push_back(temp->val);
        //     temp = temp->next;
        // }
        // vector<int> ans;
        // stack<int> s;
        // for(int i = v.size()-1 ; i>=0 ; i--){
        //     while(!s.empty() && s.top()<=v[i])
        //         s.pop();
        //     if(s.empty())
        //         ans.push_back(0);
        //     else
        //         ans.push_back(s.top());
        //     s.push(v[i]);
        //     }
        // reverse(ans.begin(),ans.end());
        // return ans;
        
        vector<int> res;
        stack<int> s;
        for(auto n = head ; n != nullptr ; n = n->next) res.push_back(n->val);
        for(int i = res.size()-1 ; i>=0 ; i--){
            auto val = res[i];
            while(!s.empty() && s.top() <= val)
                s.pop();
            res[i] = s.empty() ? 0 : s.top();
            s.push(val);
        }
        return res;
    }
};