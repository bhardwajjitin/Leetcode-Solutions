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
    void solve(TreeNode*root,string ans,string&mini){
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL){
            ans+=root->val+'a';
            string temp=ans;
            reverse(temp.begin(),temp.end());
            if(mini=="" || mini>temp){
                mini=temp;
            }
            return;
        }
        ans+=root->val+'a';
        solve(root->left,ans,mini);
        solve(root->right,ans,mini);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string mini="";
        solve(root,"",mini);
        return mini;
    }
};