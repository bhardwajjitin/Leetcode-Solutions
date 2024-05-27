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
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(4,-1)));
        // return solve(n,0,0,dp)%mod;
// // tabulation
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(4,1)));
        // for(int i=0;i<=n;i++){
        //   for(int j=0;j<2;j++){
        //     dp[i][j][3]=0;
        //   }
        // }
        // for(int i=0;i<=n;i++){
        //   for(int j=0;j<3;j++){
        //     dp[i][2][j]=0;
        //   }
        // }
        // for(int i=1;i<=n;i++){
        //   for(int a=0;a<=1;a++){
        //     for(int l=0;l<=2;l++){
        //       long long first=dp[i-1][a+1][0];
        //       long long second=dp[i-1][a][l+1];
        //       long long third=dp[i-1][a][0];
        //       dp[i][a][l]=(first+second+third)%mod;
        //     }
        //   }
        // }
        // return dp[n][0][0];

        // space optimisation
        vector<vector<int>>prev(3,vector<int>(4,1)),curr(3,vector<int>(4,0));
        for(int j=0;j<2;j++){
            prev[j][3]=0;
        }
        for(int j=0;j<3;j++){
            prev[2][j]=0;
        }
        for(int i=1;i<=n;i++){
          for(int a=0;a<=1;a++){
            for(int l=0;l<=2;l++){
              long long first=prev[a+1][0];
              long long second=prev[a][l+1];
              long long third=prev[a][0];
              curr[a][l]=(first+second+third)%mod;
            }
          }
          prev=curr;
        }
        return prev[0][0];
    }
};