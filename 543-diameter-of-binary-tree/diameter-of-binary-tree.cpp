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
int height(TreeNode* node) {
  
    // Base case: tree is empty
    if (node == nullptr)
        return 0;

    // If tree is not empty then height = 1 +
    // max of left height and right heights
    return 1 + max(height(node->left), 
                   height(node->right));
}

// Function to get diameter of a binary tree
int diameter(TreeNode* tree) {
  
    if (tree == nullptr)
        return 0;

    // Get the height of left and right sub-trees
    int lheight = height(tree->left);
    int rheight = height(tree->right);

    // Get the diameter of left and right sub-trees
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);

    // Return max of the following three:
    // 1) Diameter of left subtree
    // 2) Diameter of right subtree
    // 3) Height of left subtree + height of right subtree + 1
    return max({lheight + rheight + 1, ldiameter, rdiameter});
}
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root)-1;
    }
};