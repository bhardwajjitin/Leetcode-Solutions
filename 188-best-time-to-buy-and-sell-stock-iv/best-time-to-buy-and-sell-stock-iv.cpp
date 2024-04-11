class Solution {
    private:
    int solve(vector<int>&prices,int n,int ind,int k,int buy,vector<vector<vector<int>>>&dp){
        if(ind>=n)return 0;
        if(k==0)return 0;
        if(dp[ind][buy][k]!=-1)return dp[ind][buy][k];
        long profit=0;
        if(buy){
            profit=max(-prices[ind]+solve(prices,n,ind+1,k,0,dp),0+solve(prices,n,ind+1,k,1,dp));
        }
        else{
            profit=max(prices[ind]+solve(prices,n,ind+1,k-1,1,dp),0+solve(prices,n,ind+1,k,0,dp));
        }
        return dp[ind][buy][k]=profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,n,0,k,1,dp);
    }
};