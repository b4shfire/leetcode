// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    
    TreeNode* _flatten(TreeNode* root, TreeNode* post) {
        
        if (root == nullptr) return post;
        
        root->right = _flatten(root->right, post);
        root->left = _flatten(root->left, root->right);

        root->right = root->left;
        root->left = nullptr;
        
        return root;
    }
    
public:
    void flatten(TreeNode* root) {
        
        _flatten(root, nullptr);
    }
};
