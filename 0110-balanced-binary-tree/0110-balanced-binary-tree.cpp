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

     int height(TreeNode* root){
        if(root == NULL) return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);

        return max(lh,rh)+1;
     }

public:
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL) return true;

        int lheight = height(root->left);
        int rheight = height(root->right);

      if(isBalanced(root->left) && isBalanced(root->right) && abs(lheight-rheight) <2 ){
        return true;
      }




     return  false;
    }
};