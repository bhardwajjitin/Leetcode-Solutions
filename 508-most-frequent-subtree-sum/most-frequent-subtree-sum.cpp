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
   int solve(TreeNode*root,unordered_map<int,int>&umap,int&maxi){
      if(root==NULL)return 0;
      int temp=solve(root->left,umap,maxi)+solve(root->right,umap,maxi)+root->val;
      umap[temp]++;
      maxi=max(umap[temp],maxi);
      return temp;
   }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>umap;
        int maxi=0;
        solve(root,umap,maxi);
        vector<int>ans;
        for(auto&it:umap) if(it.second==maxi) ans.push_back(it.first);
        return ans;
    }
};