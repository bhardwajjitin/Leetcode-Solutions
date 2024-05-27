class Solution {
  int mod=1e9+7;
  private:
    int solve(int n,int a,int l,vector<vector<vector<int>>>&dp){
      if(a>=2){
        a=0;
        return 0;
      }
      if(l>=3){
        return 0;
      }
      if(n==0){
        return 1;
      }
      if(dp[n][a][l]!=-1)return dp[n][a][l];
      long long first=solve(n-1,a+1,0,dp);
      long long second=solve(n-1,a,l+1,dp);
      long long third=solve(n-1,a,0,dp);
      return dp[n][a][l]=(first+second+third)%mod;
    }
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(4,-1)));
        return solve(n,0,0,dp)%mod;
    }
};