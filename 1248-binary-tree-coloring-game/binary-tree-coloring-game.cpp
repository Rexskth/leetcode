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
    // Helper to count number of nodes in a subtree
    int count(TreeNode* root) {
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if (!root) return false;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();

            // ✅ When we find node x
            if (curr->val == x) {
                int leftCount = count(curr->left);
                int rightCount = count(curr->right);
                int parentCount = n - (1 + leftCount + rightCount);

                int maxPart = max({leftCount, rightCount, parentCount});
                return maxPart > n / 2;
            }

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        return false; // in case x is not found
    }
};
