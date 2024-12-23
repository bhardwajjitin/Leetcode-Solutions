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
    int minimumOperations(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<int>v;
        int cnt=0;
        while(!q.empty()){
            int size=q.size();
            int count=0;
            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                v.push_back(temp->val);
            }
            for(int i=0;i<v.size()-1;i++){
                int index=i+1;
                int mini=v[i+1];
                for(int j=i+1;j<v.size();j++){
                     if(mini>v[j]){
                         index=j;
                         mini=v[j];
                     }
                }
                if(v[i]>v[index]){
                swap(v[index],v[i]);
                count++;
                }
            }
            cnt+=count;
            v.clear();
        }
        return cnt;
    }
};