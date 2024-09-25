class Solution {
    private:
    int solve(vector<int>&nums,int ind,int prev,vector<vector<int>>&dp){
        if(ind>=nums.size())return 0;


        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        int notpick=solve(nums,ind+1,prev,dp);
        int pick=0;
        if(prev==-1 || nums[ind]>nums[prev]){
            pick=1+solve(nums,ind+1,ind,dp);
        }
        return dp[ind][prev+1]=max(pick,notpick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        //recursive solution
        // return solve(nums,0,-1); 
        // memo solution
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums,0,-1,dp);
    }
};