// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    
    void _connect(Node* root, Node* right_node) {
        
        root->next = right_node;
        
        if (root->left == nullptr && root->right == nullptr) return;

        // find the node immediately to the right of this node's children        
        Node* next_right = nullptr;
        
        for (Node* test = right_node; test != nullptr; test = test->next) {
            if (test->left != nullptr) {
                next_right = test->left;
                break;
            } else if (test->right != nullptr) { 
                next_right = test->right;
                break;
            }
        }
        
        // recurse
        if (root->left == nullptr) {
            _connect(root->right, next_right);
        } else if (root->right == nullptr) {
            _connect(root->left, next_right);
        } else {
            _connect(root->right, next_right);
            _connect(root->left, root->right);
        }
    }
    
public:
    Node* connect(Node* root) {
        if (root != nullptr) _connect(root, nullptr);
        return root;
    }
};
