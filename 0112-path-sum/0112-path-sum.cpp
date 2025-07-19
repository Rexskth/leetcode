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
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false; // Base case: empty tree

    
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }

       
        int newTarget = targetSum - root->val;

        return hasPathSum(root->left, newTarget) || hasPathSum(root->right, newTarget);
    }
};