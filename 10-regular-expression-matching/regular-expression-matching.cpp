class Solution {
  private:
  bool solve(string&s,string&p,int i,int j,vector<vector<int>>&dp){
    if(i<0 && j<0)return true;
    if(i<0 && j>=0){
      stack<char>st;
      for(int k=0;k<=j;k++){
        if((p[k]>='a' && p[k]<='z') || (p[k]=='.')){
          st.push(p[k]);
        }
        else{
          if(!st.empty()){
          st.pop();
          }
        }
      }
      if(st.size()>0)return false;
      return true;
    }
    if(i>=0 && j<0)return false;
    
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==p[j] || p[j]=='.'){
      return dp[i][j]=solve(s,p,i-1,j-1,dp);
    }
    if(p[j]=='*'){
       if(s[i]==p[j-1] || p[j-1]=='.'){
        return dp[i][j]=(solve(s,p,i-1,j,dp)|solve(s,p,i,j-2,dp));
       }
       else{
         return dp[i][j]=solve(s,p,i,j-2,dp);
       }
    }
    return dp[i][j]=false;
  }
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s,p,n-1,m-1,dp);
    }
};