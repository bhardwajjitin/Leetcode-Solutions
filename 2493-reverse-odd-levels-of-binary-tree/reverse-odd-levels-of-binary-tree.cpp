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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int>Ans;
        queue<TreeNode*>q;
        q.push(root);
        vector<int>arr;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                q.pop();
                if(level%2!=0){
                    temp->val=arr[i];
                }             
                if(temp->left){
                    q.push(temp->left);
                     if(level%2==0){
                        arr.push_back(temp->left->val);
                    }
                }
                if(temp->right){
                    q.push(temp->right);
                    if(level%2==0){
                        arr.push_back(temp->right->val);
                    }
                }
            }
            if(level%2!=0){
                arr.clear();
            }
            else{
                reverse(arr.begin(),arr.end());
            }
            level++;
        }
        return root;
    }
};