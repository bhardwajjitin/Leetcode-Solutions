class Solution {
private:
    int solve(vector<int>& prices, int ind, int buy, int k, int n,
              vector<vector<vector<int>>>& dp) {
        if (ind >= n)
            return 0;
        if (k >= 2)
            return 0;
        if (dp[ind][buy][k] != -1)
            return dp[ind][buy][k];
        long profit = 0;
        if (buy) {
            profit = max(-prices[ind] + solve(prices, ind + 1, 0, k, n, dp),
                         0 + solve(prices, ind + 1, 1, k, n, dp));
        } else {
            profit = max(prices[ind] + solve(prices, ind + 1, 1, k + 1, n, dp),
                         0 + solve(prices, ind + 1, 0, k, n, dp));
        }
        return dp[ind][buy][k] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        // return solve(prices,0,1,0,n,dp);
        // vector<vector<vector<int>>> dp(
            // n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        // dp[n][0][0]=0;
        // dp[n][0][1]=0;
        // dp[n][0][2]=0;
        // dp[n][1][0]=0;
        // dp[n][1][1]=0;
        // dp[n][1][2]=0;
        // for(int i=0;i<=n;i++){
        //   for(int j=0;j<=1;j++){
        //     dp[i][j][2]=0;
        //   }
        // }
        // for (int ind = n - 1; ind >= 0; ind--) {
        //     for (int buy = 0; buy <= 1; buy++) {
        //         for (int k = 1; k >= 0; k--) {
        //             long profit = 0;
        //             if (buy) {
        //                 profit = max(-prices[ind] + dp[ind + 1][0][k],
        //                              0 + dp[ind + 1][1][k]);
        //             } else {
        //                 profit = max(prices[ind] + dp[ind + 1][1][k + 1],
        //                              0 + dp[ind + 1][0][k]);
        //             }
        //             dp[ind][buy][k] = profit;
        //         }
        //     }
        // }
        // return dp[0][1][0];
        vector<vector<int>>prev(2, vector<int>(3, 0)),curr(2,vector<int>(3,0));
          for(int j=0;j<=1;j++){
            prev[j][2]=0;
          }
          for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
              for(int k=1;k>=0;k--){
                if(buy){
                  curr[buy][k]=max(-prices[ind]+prev[0][k],0+prev[1][k]);
                }
                else{
                  curr[buy][k]=max(prices[ind]+prev[1][k+1],0+prev[0][k]);
                }
              }
            }
            prev=curr;
          }
        return prev[1][0];
    }
};