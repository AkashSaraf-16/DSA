/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;  // orginal-new
        Node* curr=head;
        // Creating single nodes from the Original LL
        while(curr){
            Node* copy=new Node(curr->val);
            mp[curr]=copy;
            curr=curr->next;
        }
        // Making the connection
        curr=head;
        while(curr){
            Node* n=mp[curr->next];
            Node* r=mp[curr->random];
            mp[curr]->next=n;
            mp[curr]->random=r;
            curr=curr->next;
        }
        return mp[head];
        
    }
};