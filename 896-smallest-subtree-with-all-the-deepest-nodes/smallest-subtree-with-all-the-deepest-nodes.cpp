class Solution {
  private:
  pair<int,TreeNode*>solve(TreeNode*root,int depth){
    if(root==NULL)return {depth+1,NULL};
    pair<int,TreeNode*>l=solve(root->left,depth+1);
    pair<int,TreeNode*>r=solve(root->right,depth+1);
    if(l.first!=r.first){
      return l.first>r.first?l:r;
    }
    return {l.first,root};
  }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root,0).second;
    }
};