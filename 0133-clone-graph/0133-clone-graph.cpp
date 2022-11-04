/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // TC:O(V*E) SC:O(1)
    unordered_map<Node*,Node*> mp;  //key:original node ref value:copy node ref
    Node* helper(Node* node){
        if(mp.find(node) != mp.end()){
            return mp[node];
        }
        Node* copy=new Node(node->val);
        mp[node]=copy;
        for(Node* neighbor:node->neighbors){
            copy->neighbors.push_back(helper(neighbor));
        }
        return mp[node] ? mp[node] : NULL;
    }
    Node* cloneGraph(Node* node) {
        if(!node)
            return node;
        return helper(node);
    }
};