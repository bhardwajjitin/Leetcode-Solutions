class Solution {
  private:
  int solve(vector<int>&nums,int ind,int n,vector<int>&dp){
    if(ind==n-1)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int mini=1e5;
    for(int step=0;step<=nums[ind];step++){
      if(ind+step<n && ind+step!=ind){
      int ans=1+solve(nums,ind+step,n,dp);
      mini=min(ans,mini);
      }
    }
    return dp[ind]=mini;
  }
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        int ans=solve(nums,0,n,dp);
        return ans;
    }
};