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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        int maxi=INT_MIN;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
          int size=q.size();
          int left=q.front().second;
          int right;
          for(int i=0;i<size;i++){
              TreeNode*curr=q.front().first;
              int no=q.front().second;
              right=no;
              q.pop();
              if(curr->left){
                q.push({curr->left,(long long)2*no+1});
              }
              if(curr->right){
                q.push({curr->right,(long long)2*no+2});
              }
           
          }
          int maxi=right-left+1;
          cout<<right<<" "<<left<<endl;
          ans=max(ans,maxi);
        }
        return ans;
    }
};