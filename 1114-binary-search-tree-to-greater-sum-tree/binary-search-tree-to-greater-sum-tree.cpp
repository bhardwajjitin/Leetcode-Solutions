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
  int solve(TreeNode*&root,int&sum){
    if(root==NULL)return 0;
    int right=solve(root->right,sum);
    root->val+=sum;
    sum=root->val;
    int left=solve(root->left,sum);
    return sum;
  }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        solve(root,sum);
        return root;
    }
};