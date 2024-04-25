class Solution {
  private:
  int solve(string&s,int k,int ind,int prev,vector<vector<int>>&dp){
    if(ind<0)return 0;
    if(dp[ind][prev]!=-1)return dp[ind][prev];
    int exclude=solve(s,k,ind-1,prev,dp);
    int include=INT_MIN;
    if(prev==0 || abs(s[ind]-prev)<=k){
      include=1+solve(s,k,ind-1,s[ind],dp);
    }
    return dp[ind][prev]=max(include,exclude);
  }
public:
    int longestIdealString(string s, int k) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(150,-1));
        return solve(s,k,n-1,0,dp);
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        // for(int ind=n-1;ind>=0;ind--){
        //   for(int prev=ind-1;prev>=-1;prev--){
        //     int exclude=dp[ind+1][prev+1];
        //     int include=INT_MIN;
        //     if(prev==-1 || abs(s[ind]-s[prev])<=k){
        //       include=1+dp[ind+1][ind+1];
        //     }
        //     dp[ind][prev+1]=max(include,exclude);
        //   }
        // }
        // return dp[0][0];

        // space optimisation
        // vector<int>previ(n+1,0),curr(n+1,0);
        // for(int ind=n-1;ind>=0;ind--){
        //   for(int prev=ind-1;prev>=-1;prev--){
        //     int exclude=previ[prev+1];
        //     int include=INT_MIN;
        //     if(prev==-1 || abs(s[ind]-s[prev])<=k){
        //       include=1+previ[ind+1];
        //     }
        //     curr[prev+1]=max(include,exclude);
        //   }
        //   previ=curr;
        // }
        // return previ[0];
    }
};