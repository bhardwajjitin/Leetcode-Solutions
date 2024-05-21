class Solution {
  private:
  void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>v,int ind){
    if(ind>=nums.size()){
      ans.push_back(v);
      return;
    }
    v.push_back(nums[ind]);
    solve(nums,ans,v,ind+1);
    v.pop_back();
    solve(nums,ans,v,ind+1);
  }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(nums,ans,{},0);
        return ans;
    }
};