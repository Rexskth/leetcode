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
   private:

   bool check(TreeNode* root, long mx, long mn){
    if(root == nullptr){
        return true;
    }

    if(root->val >= mx || root->val <= mn){
        return false;
    }


    return check(root->left, root->val, mn) && 
           check(root->right, mx, root->val);

   }
public:
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MAX, LONG_MIN);
    }
};