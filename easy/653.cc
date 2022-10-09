// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    void _next(TreeNode*& node, stack<TreeNode*>& st) {

        if (node->right == nullptr) {
            node = st.top(); st.pop();
        } else {
            node = node->right;
            while (node->left != nullptr) {
                st.push(node);
                node = node->left;
            }
        }
    }
    
    void _prev(TreeNode*& node, stack<TreeNode*>& st) {
        
        if (node->left == nullptr) {
            node = st.top(); st.pop();
        } else {
            node = node->left;            
            while (node->right != nullptr) {
                st.push(node);
                node = node->right;
            }
        }
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        
        TreeNode sentinel(0, root, root);
        
        TreeNode* l=&sentinel, *r=&sentinel;
        stack<TreeNode*> l_stack, r_stack;
        
        _next(l, l_stack);
        _prev(r, r_stack);
        
        while (l != r) {
            if (l->val + r->val < k)
                _next(l, l_stack);
            else if (l->val + r->val > k)
                _prev(r, r_stack);
            else
                return true;
        }
        
        return false;
    }
};
