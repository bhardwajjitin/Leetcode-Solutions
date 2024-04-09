class Solution {
    private:
    int solve(string word1,string word2,int i,int j,vector<vector<int>>&dp){
         if(i>=word1.size() && j>=word2.size()){
            return 0;
        }
        if(i>=word1.size() && j<word2.size()){
            return word2.size()-j;
        }
        if(i<word1.size() && j>=word2.size()){
            return word1.size()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=INT_MAX;
        int del=INT_MAX;
        int ins=INT_MAX;
        int a=INT_MAX;
        if(word1[i]!=word2[j]){

            ins=1+solve(word1,word2,i,j+1,dp);

            up=1+solve(word1,word2,i+1,j+1,dp);

            del=1+solve(word1,word2,i+1,j,dp);
            
        }
        else
          a=solve(word1,word2,i+1,j+1,dp);

        return dp[i][j]=min(up,min(ins,min(a,del)));
    }
public:
    int minDistance(string word1, string word2) {
        // vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        // int ans=solve(word1,word2,0,0,dp);
        // return ans;
        int m=word1.size();
        int n=word2.size();
        // vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        // dp[0][0]=0;
        // for(int i=1;i<=m;i++){
        //     dp[i][0]=i;
        // }
        // for(int j=1;j<=n;j++){
        //     dp[0][j]=j;
        // }
        // for(int i=1;i<=m;i++){
        //     for(int j=1;j<=n;j++){
        //         if(word1[i-1]!=word2[j-1]){
        //             dp[i][j]=min(1+dp[i-1][j],min(1+dp[i-1][j-1],1+dp[i][j-1]));
        //         }
        //         else{
        //             dp[i][j]=dp[i-1][j-1];
        //         }
        //     }
        // }
        // return dp[m][n];
        // space opti
        vector<int>prev(n+1,0),curr(n+1,0);
        prev[0]=0;
        for(int j=1;j<=n;j++){
            prev[j]=j;
        }
        for(int i=1;i<=m;i++){
            curr[0]=i;
            for(int j=1;j<=n;j++){
                if(word1[i-1]!=word2[j-1]){
                    curr[j]=min(1+prev[j],min(1+prev[j-1],1+curr[j-1]));
                }
                else{
                    curr[j]=prev[j-1];
                }
            }
            prev=curr;
        }
        return prev[n];
    }
};