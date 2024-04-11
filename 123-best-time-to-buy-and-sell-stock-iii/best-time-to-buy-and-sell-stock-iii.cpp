class Solution {
    private:
    int solve(vector<int>&prices,int ind,int buy,int k,int n,vector<vector<vector<int>>>&dp){
        if(ind>=n)return 0;
        if(k>=2)return 0;
        if(dp[ind][buy][k]!=-1)return dp[ind][buy][k];
        long profit=0;
        if(buy){
           profit=max(-prices[ind]+solve(prices,ind+1,0,k,n,dp),0+solve(prices,ind+1,1,k,n,dp));
        }
        else{
            profit=max(prices[ind]+solve(prices,ind+1,1,k+1,n,dp),0+solve(prices,ind+1,0,k,n,dp));
        }
        return dp[ind][buy][k]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(prices,0,1,0,n,dp);
    }
};