class Solution {
    private:
    int solve(vector<int>&prices,int ind,int buy,vector<vector<int>>&dp){
        if(ind==prices.size())return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        long profit=0;
        if(buy){
            profit=max(-prices[ind]+solve(prices,ind+1,0,dp),0+solve(prices,ind+1,1,dp));
        }
        else{
            profit=max(prices[ind]+solve(prices,ind+1,1,dp),0+solve(prices,ind+1,0,dp));
        }
        return dp[ind][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        // return solve(prices,0,1,dp);
        // bottom up
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        // dp[n][0]=0,dp[n][1]=0;
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<=1;buy++){
        //         long profit=0;
        //         if(buy){
        //             profit=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
        //         }
        //         else{
        //             profit=max(prices[ind]+dp[ind+1][1],0+dp[ind+1][0]);
        //         }
        //         dp[ind][buy]=profit;
        //     }
        // }
        // return dp[0][1];
        // space opti
        vector<int>prev(2,0),curr(2,0);
        prev[0]=0,prev[1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                long profit=0;
                if(buy){
                    profit=max(-prices[ind]+prev[0],0+prev[1]);
                }
                else{
                    profit=max(prices[ind]+prev[1],0+prev[0]);
                }
                curr[buy]=profit;
            }
            prev=curr;
        }
        return prev[1];
    }
};