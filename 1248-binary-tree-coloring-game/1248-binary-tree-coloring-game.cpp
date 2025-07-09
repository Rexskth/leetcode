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

        TreeNode* target = nullptr;

        // Level Order Traversal to find node x
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();

            if (curr->val == x) {
                target = curr;
                break;
            }

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        if (!target) return false; // x not found

        // Now count left and right subtrees of x
        int leftCount = count(target->left);
        int rightCount = count(target->right);
        int parentCount = n - (1 + leftCount + rightCount);

        int maxPart = max({leftCount, rightCount, parentCount});

        return maxPart > n / 2;
    }
};
