// https://leetcode.com/problems/clone-graph/

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
    Node* cloneGraph(Node* node) {
        
        if (node == nullptr) return nullptr;
        
        Node* start = new Node(node->val);
        
        // maps p_original => p_copy for all copied nodes
        unordered_map<Node*, Node*> copies = {{node, start}};
        queue<Node*> todo({node});
        
        while (!todo.empty()){
            
            Node* old = todo.front();
            Node* copy = copies[old];
            todo.pop();
            
            // copy each of the old node's neighbours
            for (Node* adj : old->neighbors){
                
                Node* adj_copy = nullptr;
                auto itr = copies.find(adj);
                
                // if we have already copied this node, don't copy it again
                if (itr == copies.end()){
                    adj_copy = new Node(adj->val);
                    copies[adj] = adj_copy;
                    todo.push(adj);
                }else{
                    adj_copy = itr->second;
                }
                
                copy->neighbors.push_back(adj_copy);
            }
        }
        
        return start;
    }
};
