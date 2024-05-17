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
  TreeNode* solve(TreeNode* root,int target){
    if(root==NULL)return root;
    
    TreeNode* left=solve(root->left,target);
    TreeNode* right=solve(root->right,target);

    root->left=left;
    root->right=right;

    if(left==NULL && right==NULL){
      if(root->val==target){
      //  delete root;
       return NULL;
      }
    }
    return root;
  }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return solve(root,target);
    }
};