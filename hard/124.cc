// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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

    // returns {max path in subtree, max path in subtree which terminates at root}
    pair<int,int> _subtree_info(TreeNode* root) {

        if (root == nullptr)
            return {-1000, 0}; // -1000 because the path must include at least one node

        pair<int,int> left = _subtree_info(root->left);
        pair<int,int> right = _subtree_info(root->right);

        return {
            max({
                left.first, right.first, 
                max({0, left.second, right.second, left.second + right.second}) + root->val
                }), 
            max({0, left.second, right.second}) + root->val
            };
    }

public:
    int maxPathSum(TreeNode* root) {
        return _subtree_info(root).first;
    }
};
