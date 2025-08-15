class Solution {
    private:
    long long solve(vector<int>&coins,int amount,int index,vector<vector<int>>&dp){
        if(index>=coins.size()){;
            if(amount==0)return 0;
            else return INT_MAX;
        }
        if(dp[index][amount]!=-1)return dp[index][amount];
        long long include=INT_MAX;
        if(amount>=coins[index]){
        include=1+solve(coins,amount-coins[index],index,dp);
        }
        long long exclude=solve(coins,amount,index+1,dp);

        return dp[index][amount]=min(include,exclude);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        long long ans=solve(coins,amount,0,dp);
        return ans==INT_MAX?-1:ans;
    }
};