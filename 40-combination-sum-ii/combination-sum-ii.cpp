class Solution {
    private:
    void solve(vector<int>&candidates,int target,int index,vector<int>&ans,vector<vector<int>>&res){
        
        if(target==0){
            res.push_back(ans);
            return;
        }

        for(int i=index;i<candidates.size();i++){
            if(i > index && candidates[i] == candidates[i-1]) continue;
            if(target<candidates[i])break;
            ans.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i+1,ans,res);
            ans.pop_back();    
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ans;
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        solve(candidates,target,0,ans,res);
        return res;
    }
};