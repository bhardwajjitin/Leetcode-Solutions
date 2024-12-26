class Solution {
    private:
    int solve(vector<int>&nums,int ind,int target,vector<vector<int>>&dp){
        if(ind>=nums.size()){
            if(target==0)return 1;
            return 0;
        }
        if(dp[ind][target+2000]!=-1)return dp[ind][target+2000];
        int plus=solve(nums,ind+1,target+nums[ind],dp);
        int sub=solve(nums,ind+1,target-nums[ind],dp);
        return dp[ind][target+2000]=plus+sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size(),vector<int>(4001,-1));
        return solve(nums,0,target,dp);
    }
};