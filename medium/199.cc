// https://leetcode.com/problems/binary-tree-right-side-view/

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
    
    void _rightSideView(TreeNode* root, vector<int>& ans, int depth) {
        
        if (root == nullptr) return;
        
        if (depth == ans.size())
            ans.push_back(root->val);
        
        _rightSideView(root->right, ans, depth+1);
        _rightSideView(root->left, ans, depth+1);
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        _rightSideView(root, ans, 0);
        return ans;
    }
};
