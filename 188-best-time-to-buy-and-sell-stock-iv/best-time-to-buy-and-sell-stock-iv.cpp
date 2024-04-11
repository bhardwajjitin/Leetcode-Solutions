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
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return solve(prices,n,0,k,1,dp);
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        // // no need fill the base cases as initially it is zero
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int buy=0;buy<=1;buy++){
        //         for(int j=1;j<=k;j++){
                
        //         if(buy){
        //             dp[ind][buy][j]=max(-prices[ind]+dp[ind+1][0][j],0+dp[ind+1][1][j]);
        //         }
        //         else{
        //             dp[ind][buy][j]=max(prices[ind]+dp[ind+1][1][j-1],0+dp[ind+1][0][j]);
        //         }

        //         }
        //     }
        // }
        // return dp[0][1][k];

        // space optimisation
        vector<vector<int>>prev(2,vector<int>(k+1,0)),curr(2,vector<int>(k+1,0));
        // no need fill the base cases as initially it is zero
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int j=1;j<=k;j++){
                
                if(buy){
                    curr[buy][j]=max(-prices[ind]+prev[0][j],0+prev[1][j]);
                }
                else{
                    curr[buy][j]=max(prices[ind]+prev[1][j-1],0+prev[0][j]);
                }
                }
            }
            prev=curr;
        }
        return prev[1][k];
    }
};