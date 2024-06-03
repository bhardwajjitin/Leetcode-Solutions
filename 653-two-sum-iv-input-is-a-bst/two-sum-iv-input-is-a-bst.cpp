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
    void traverse(TreeNode* root , unordered_map<int,int>&valuesTillNow , int k , bool& ans){
        if(ans)return;
        if(root == NULL)return;
        traverse(root->left , valuesTillNow , k,ans);
        if(valuesTillNow.find((k-root->val)) != valuesTillNow.end())ans = true;
        valuesTillNow[root->val] = 1;
        traverse(root->right,valuesTillNow,k,ans);
       
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        bool ans = 0;
        unordered_map<int,int>valuesTillNow;
        traverse(root,valuesTillNow,k,ans);
        return ans;
    }
};