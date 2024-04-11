class Solution {
    private:
    int solve(vector<int>&prices,int fee,int ind,int buy,vector<vector<int>>&dp){
        if(ind==prices.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        long profit=0;
        if(buy){
            profit=max(-prices[ind]+solve(prices,fee,ind+1,0,dp),solve(prices,fee,ind+1,1,dp));
        }
        else{
            profit=max((prices[ind]-fee)+solve(prices,fee,ind+1,1,dp),solve(prices,fee,ind+1,0,dp));
        }
        return dp[ind][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,fee,0,1,dp);
        // tabulation
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        // no need to write base case as prefilled in dp
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<=1;buy++){
        //         int profit=0;
        //         if(buy){
        //             profit=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
        //         }
        //         else{
        //             profit=max((prices[ind]-fee)+dp[ind+1][1],dp[ind+1][0]);
        //         }
        //     dp[ind][buy]=profit;
        //     }
        // }
        // return dp[0][1];

        // space optimisation
        // vector<int>prev(2,0),curr(2,0);
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<=1;buy++){
        //         int profit=0;
        //         if(buy){
        //             profit=max(-prices[ind]+prev[0],prev[1]);
        //         }
        //         else{
        //             profit=max((prices[ind]-fee)+prev[1],prev[0]);
        //         }
        //     curr[buy]=profit;
        //     }
        //     prev=curr;
        // }
        // return prev[1];
    }
};