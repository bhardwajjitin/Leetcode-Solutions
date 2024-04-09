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
        int n=s.size();
        int m=p.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return solve(s,p,n,m,dp);
        // bottom up
        // vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        // dp[0][0]=true;
        // for(int i=1;i<=n;i++){
        //    dp[i][0]=false;
        // }
        // for(int j=1;j<=m;j++){
        //     bool flag=true;
        //     for(int k=1;k<=j;k++){
        //         if(p[k-1]!='*'){
        //             flag=false;
        //             break;
        //         }
        //     }
        //     dp[0][j]=flag;
        // }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(p[j-1]==s[i-1] || p[j-1]=='?'){
        //             dp[i][j]=dp[i-1][j-1];
        //         }
        //         else if(p[j-1]=='*'){
        //             dp[i][j]=dp[i-1][j]|dp[i][j-1];
        //         }
        //         else{
        //             dp[i][j]=false;
        //         }
        //     }
        // }
        // return dp[n][m];
        vector<bool>prev(m+1,false),curr(m+1,false);
        prev[0]=true;
        for(int i=1;i<=m;i++){
            bool flag=true;
            for(int k=1;k<=i;k++){
                if(p[k-1]!='*'){
                    flag=false;
                    break;
                }
            }
            prev[i]=flag;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]==s[i-1] || p[j-1]=='?'){
                   curr[j]=prev[j-1];
                }
                else if(p[j-1]=='*'){
                    curr[j]=prev[j]|curr[j-1];
                }
                else{
                    curr[j]=false;
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};