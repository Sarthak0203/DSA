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
        if(!head) return nullptr;
        unordered_map<Node*, Node*> o;
        Node* cur = head;
        while(cur){
            o[cur]= new Node(cur->val);
            cur=cur->next;
        }
        cur=head;
        while(cur){
            o[cur]->next=o[cur->next];
            o[cur]->random=o[cur->random];
            cur=cur->next;
        }
        return o[head];
    }
};