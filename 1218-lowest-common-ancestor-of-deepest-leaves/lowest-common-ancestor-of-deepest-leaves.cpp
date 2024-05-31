class Solution {
  private:
  pair<int,TreeNode*>solve(TreeNode*root,int depth){
    if(root==NULL)return {depth,NULL};
    pair<int,TreeNode*>l=solve(root->left,depth+1);
    pair<int,TreeNode*>r=solve(root->right,depth+1);
    if(l.first!=r.first){
       if(l.first>r.first){
        return l;
       }
       else{
        return r;
       }
    }
    return {l.first,root};
  }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
         return  solve(root,0).second;
         
    }
};