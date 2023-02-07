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
        // unordered_map<Node*,Node*> mp;  // orginal-new
        // Node* curr=head;
        // // Creating single nodes from the Original LL
        // while(curr){
        //     Node* copy=new Node(curr->val);
        //     mp[curr]=copy;
        //     curr=curr->next;
        // }
        // // Making the connection
        // curr=head;
        // while(curr){
        //     Node* n=mp[curr->next];
        //     Node* r=mp[curr->random];
        //     mp[curr]->next=n;
        //     mp[curr]->random=r;
        //     curr=curr->next;
        // }
        // return mp[head];
        
        
        // Optimised solution:-
        
        // Inserting new nodes in Original LL
        Node* curr=head;
        while(curr){
            Node *frnt=curr->next;
            Node *copy=new Node(curr->val);
            curr->next=copy;
            copy->next=frnt;
            curr=curr->next->next;
        }
        curr=head;
        // Set the random of new LL
        while(curr){
            curr->next->random=curr->random == NULL ?NULL:curr->random->next;
            curr=curr->next->next;
        }
        // Set the next pointers in LL and ditach the two LLs
        curr=head;
        Node* res=new Node(0);
        Node* copy=res;
        while(curr){
            Node* frnt=curr->next->next;
            copy->next=curr->next;
            curr->next=frnt;
            copy=copy->next;
            curr=curr->next;
        }
        return res->next;
    }
};