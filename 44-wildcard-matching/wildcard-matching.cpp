class Solution {
    private:
    bool solve(string&s,string&p,int i,int j,vector<vector<int>>&dp){
        if(i<0 && j<0)return true;
        if(j<0 && i>=0)return false;
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*')return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        bool inc=false,inc1=false,inc2=false,inc3=false;
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=solve(s,p,i-1,j-1,dp);
        }
        else if(p[j]=='*'){
            return dp[i][j]=solve(s,p,i-1,j,dp)|solve(s,p,i,j-1,dp);
        }
       
        return dp[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
        int n=s.size()-1;
        int m=p.size()-1;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s,p,n,m,dp);
    }
};