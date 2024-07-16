class Solution {
  private:
  bool solve(string&p,string&q,string&r,int i,int j,int k,vector<vector<vector<int>>>&dp){
    if(i==p.size() && j==q.size() && k==r.size())return true;
    if(k>=r.size() && (i<p.size() || j<q.size()))return false;
    bool a=false;
    bool b=false;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    if(p[i]==r[k]){
      a=solve(p,q,r,i+1,j,k+1,dp);
    }
    if(q[j]==r[k]){
      b=solve(p,q,r,i,j+1,k+1,dp);
    }
    return dp[i][j][k]=a||b;
  }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size();
        int n=s2.size();
        int p=s3.size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(p+1,-1)));
        return solve(s1,s2,s3,0,0,0,dp);
    }
};