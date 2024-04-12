class Solution {
    private:
    int solve(vector<int>&nums,int ind,int ind1,vector<vector<int>>&dp){
        if(ind==nums.size())return 0;
        if(dp[ind][ind1+1]!=-1){
            return dp[ind][ind1+1];
        }
        int inc=0;
        int exc=solve(nums,ind+1,ind1,dp);
        if(ind1==-1 || nums[ind]>nums[ind1]){
            inc=1+solve(nums,ind+1,ind,dp);
        }
        return dp[ind][ind1+1]=max(inc,exc);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solve(nums,0,-1,dp);
        // bottom up
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int ind1=ind-1;ind1>=-1;ind1--){
        //         int inc=0;
        //         int exc=dp[ind+1][ind1+1];
        //         if(ind1==-1 || nums[ind]>nums[ind1]){
        //             inc=1+dp[ind+1][ind+1];
        //         }
        //         dp[ind][ind1+1]=max(inc,exc);
        //     }
        // }
        // return dp[0][0];
        // space optimisation
        vector<int>prev(n+1,0),curr(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int ind1=ind-1;ind1>=-1;ind1--){
                int inc=0;
                int exc=prev[ind1+1];
                if(ind1==-1 || nums[ind]>nums[ind1]){
                    inc=1+prev[ind+1];
                }
                curr[ind1+1]=max(inc,exc);
            }
            prev=curr;
        }
        return prev[0];
    }
};