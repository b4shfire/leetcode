// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

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

    // returns sum of nodes in subtree, also pushes result to vector
    int _subtree_sum(vector<int>& sums, TreeNode* root) {
        
        if (root == nullptr)
            return 0;

        int sum = root->val;
        
        sum += _subtree_sum(sums, root->left);
        sum += _subtree_sum(sums, root->right);

        sums.push_back(sum);
        return sum;
    }

public:
    int maxProduct(TreeNode* root) {
        
        vector<int> sums;
        int total = _subtree_sum(sums, root);

        // the best split point is the one closest to half of the total sum
        int best_split = *max_element(sums.begin(), sums.end(),
            [total](int a, int b) {
                return abs(b - total / 2) < abs(a - total / 2);
            }
        );

        return (static_cast<int64_t>(best_split) * (total - best_split)) % 1000000007;
    }
};
