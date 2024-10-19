class Solution {
    private:
    int solve(int n,int cnta,int cntl,vector<vector<vector<int>>>&dp){
        if(n==0){
            if(cnta<2)return 1;
            return 0;
        }
        if(dp[n][cnta][cntl]!=-1)return dp[n][cnta][cntl];
        int absent=0,leave=0,present=0;
        present=solve(n-1,cnta,0,dp);
        if(cnta<1){
            absent=solve(n-1,cnta+1,0,dp);
        }
        if(cntl<2){
            leave=solve(n-1,cnta,cntl+1,dp);
        }
        return dp[n][cnta][cntl]=((long long)present+(long long)absent+(long long)leave)%1000000007;
    }
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(n,0,0,dp);
    }
};
