class Solution {
    private:
    long long solve(vector<int>&nums,int l,int ind,vector<vector<long long>>&dp,int sign){
        if(ind>=nums.size())return 0;
        
        if(dp[ind][sign+1]!=-1)return dp[ind][sign+1];
        int signpick=(ind-ind)%2==0?1:-1;
        int signnotpick=(ind-l)%2==0?1:-1;
        long long notpick=(nums[ind]*signnotpick)+solve(nums,l,ind+1,dp,signnotpick);
        long long pick=(nums[ind]*signpick)+solve(nums,ind,ind+1,dp,signpick);
        return dp[ind][sign+1]=max(notpick,pick);
    }
public:
    long long maximumTotalCost(vector<int>& nums) {
       long long sum=0;
       vector<vector<long long>>dp(nums.size(),vector<long long>(3,-1));
       return solve(nums,0,0,dp,-1);
    }
};