class Solution {
    private:
    int solve(vector<vector<int>>&grid,int i,int curr,vector<vector<int>>&dp){
        if(i==grid.size()-1){
            return grid[i][curr];
        }
        if(dp[i][curr]!=-1){
            return dp[i][curr];
        }
        int mini=INT_MAX;
        for(int j=0;j<grid[i].size();j++){
            if(j!=curr){
                int down=grid[i][curr]+solve(grid,i+1,j,dp);
                mini=min(mini,down);
            }
        }
        return dp[i][curr]=mini;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        // vector<vector<int>>dp(row,vector<int>(col,-1));
        // int mini=INT_MAX;
        // for(int i=0;i<col;i++){
        //     int ans=solve(grid,0,i,dp);
        //     mini=min(mini,ans);
        // }
        // return mini;
        // vector<vector<int>>dp(row,vector<int>(col,0));
        // for(int i=0;i<grid[row-1].size();i++){
        //     dp[row-1][i]=grid[row-1][i];
        // }
        // for(int k=row-2;k>=0;k--){
        //     for(int i=0;i<col;i++){
        //      int mini=INT_MAX;
        //     for(int j=0;j<col;j++){
        //        if(j!=i){
        //         int down=grid[k][i]+dp[k+1][j];
        //         mini=min(mini,down);
        //     }
        //     }
        //     dp[k][i]=mini;
        //     }
        // }
        // int maxi=INT_MAX;
        // for(int i=0;i<col;i++){
        //     maxi=min(dp[0][i],maxi);
        // }
        // return maxi;
        // space optimisation
        vector<int>prev(col,0),curr(col,0);
        for(int i=0;i<grid[row-1].size();i++){
            prev[i]=grid[row-1][i];
        }
        for(int k=row-2;k>=0;k--){
            for(int i=0;i<col;i++){
             int mini=INT_MAX;
            for(int j=0;j<col;j++){
               if(j!=i){
                int down=grid[k][i]+prev[j];
                mini=min(mini,down);
            }
            }
            curr[i]=mini;
            }
            prev=curr;
        }
        int maxi=INT_MAX;
        for(int i=0;i<col;i++){
            maxi=min(prev[i],maxi);
        }
        return maxi;
    }
};