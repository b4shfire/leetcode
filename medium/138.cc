// https://leetcode.com/problems/copy-list-with-random-pointer/

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
        
        if (head == nullptr) return nullptr;
        
        // maps old_node => new_node for all previously copied nodes
        unordered_map<Node*, Node*> copies = {{nullptr, nullptr}};
        
        Node* new_head = new Node(head->val);
        copies[head] = new_head;
        
        Node* old_node = head;
        Node* new_node = new_head;
        
        while (old_node != nullptr) {
            
            // copy old_node->random (taking from cache if already copied)
            auto cached_random = copies.find(old_node->random);
                
            if (cached_random == copies.end()) {
                new_node->random = new Node(old_node->random->val);
                copies[old_node->random] = new_node->random;
            } else {
                new_node->random = cached_random->second;
            }
            
            // copy old_node->next (taking from cache if already copied)
            auto cached_next = copies.find(old_node->next);
                
            if (cached_next == copies.end()) {
                new_node->next = new Node(old_node->next->val);
                copies[old_node->next] = new_node->next;
            } else {
                new_node->next = cached_next->second;
            }
            
            // move on to the next node in the list
            old_node = old_node->next;
            new_node = new_node->next;
        }
        
        return new_head;
    }
};
