class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=INT_MIN;
        vector<vector<int>>dp(m,vector<int>(n,INT_MIN));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int maxi=INT_MIN;
                for(int k=j+1;k<n;k++){
                    int diff=grid[i][k]-grid[i][j];
                    if(dp[i][k]>=0){
                        diff+=dp[i][k];
                    }
                    maxi=max(maxi,diff);
                }
                for(int k=i+1;k<m;k++){
                     int diff=grid[k][j]-grid[i][j];
                    if(dp[k][j]>=0){
                        diff+=dp[k][j];
                    }
                    maxi=max(maxi,diff);
                }
                dp[i][j]=maxi;
            }
        }
        dp[m-1][n-1]=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};