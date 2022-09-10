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
    // BRUTE FORCE: TC:O(n) SC:O(n);
        // unordered_map<Node* , Node*> mp;
        // Node* thead = head;
        // while(head){
        //     Node* node = new Node(head->val);
        //     mp[head] = node;     // first storing address of org. node adress and its corresponding new node address
        //     head = head->next;       
        // }
        // head = thead;
        // while(head){
        //     Node* curr = mp[head];
        //     Node* n = mp[head->next] ;
        //     Node* r = mp[head->random];
        //     curr->next = n;
        //     curr->random = r;
        //     head = head->next;
        // }
        // return mp[thead];
    // OPTIMAL: TC:O(n) SC: O(1)
    // step 1 : create a new LL with same values and attach them in the original LL
         Node* itr = head;
         Node* frnt = head;
         while(itr){
             frnt = itr->next;
             Node* copy = new Node(itr->val);
             itr->next = copy;
             copy->next = frnt;
             itr = frnt;
         }
    // step 2 : link the random pointers of the copied nodes
         itr = head;
         while(itr){
             itr->next->random = itr->random == NULL ? NULL : itr->random->next;
             itr = itr->next->next;
         }
    // step 3 : link the next pointers of the copied nodes and detach both the linked lists
         Node* pseudo_head = new Node(0);
         Node* copy = pseudo_head;
         itr = head;
         while(itr){
             Node* front = itr->next->next;
             copy->next = itr->next;
             itr->next = front;
             copy = copy->next;
             itr = itr->next;
         }
         return pseudo_head->next;
    }
};