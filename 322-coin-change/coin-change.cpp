class Solution {
    private:
    int solve(int index,vector<int>&coins,int amount,vector<vector<int>>&dp){
        if(amount==0){
                return 0;
        }
        if(index>=coins.size() || amount<0){    
            return 1e5;
        }
        if(dp[index][amount]!=-1){
            return dp[index][amount];
        }
        int pick=solve(index,coins,amount-coins[index],dp)+1;
        int not_pick=solve(index+1,coins,amount,dp);

        return dp[index][amount]=min(pick,not_pick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(0,coins,amount,dp);
        return ans==1e5?-1:ans;
    }
};