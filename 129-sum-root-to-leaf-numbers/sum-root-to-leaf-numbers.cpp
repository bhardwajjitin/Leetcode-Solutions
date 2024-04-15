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
    void solve(TreeNode*root,int sum,int&ans){
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL){  
            sum=sum*10+root->val;
            ans+=sum;
            return;
        }
        sum=sum*10+root->val;
        solve(root->left,sum,ans);
        solve(root->right,sum,ans);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans=0;
        solve(root,0,ans);
        return ans;
    }
};