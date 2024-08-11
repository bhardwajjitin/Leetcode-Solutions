class Solution {
    private:
    int solve(vector<int>&nums,int ind,int prev,int prev1,vector<vector<vector<int>>>&dp){
        if(ind>=nums.size()){
           return 1;
        }
        if(dp[ind][prev][prev1]!=-1)return dp[ind][prev][prev1];
        int ways=0;
        for(int i=0;i<=nums[ind];i++){
            if(i>=prev && nums[ind]-i<=prev1)
            ways=(ways+solve(nums,ind+1,i,nums[ind]-i,dp))%1000000007;
        }
        return dp[ind][prev][prev1]=ways%1000000007;
    }
public:
    int countOfPairs(vector<int>& nums) {
        long long countways=0;
        int maxi=*max_element(nums.begin(),nums.end());
        vector<vector<vector<int>>>dp(nums.size()+1,vector<vector<int>>(51,vector<int>(51,-1)));
        for(int i=0;i<=nums[0];i++){
            int prev=i;
            int prev1=nums[0]-i;
            countways=(countways+solve(nums,1,prev,prev1,dp))%1000000007;
        }
        return countways;
    }
};