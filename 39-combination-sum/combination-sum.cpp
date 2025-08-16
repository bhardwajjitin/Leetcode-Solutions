class Solution {
    private:
    void solve(vector<int>&candidates,int target,int index,vector<int>ans,vector<vector<int>>&res){
        if(index>=candidates.size()){
            if(target==0){
                res.push_back(ans);
                return;
            }
            return;
        }

        if(target>=candidates[index]){
            ans.push_back(candidates[index]);
            target-=candidates[index];
            solve(candidates,target,index,ans,res);
            ans.pop_back();
            target+=candidates[index];
        }
        solve(candidates,target,index+1,ans,res);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ans;
        vector<vector<int>>res;
        solve(candidates,target,0,ans,res);
        return res;
    }
};