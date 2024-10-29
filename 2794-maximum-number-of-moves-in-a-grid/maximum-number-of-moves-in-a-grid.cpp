class Solution {
    private:
    int solve(int currrow,int currcol,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(currcol>grid[0].size() || currrow>grid.size())return 0;
        if(dp[currrow][currcol]!=-1)return dp[currrow][currcol];
        int upside=0;
        int downside=0;
        int side=0;
        if(currrow>0 && currcol+1<grid[0].size() && grid[currrow][currcol]<grid[currrow-1][currcol+1]){
            upside=1+solve(currrow-1,currcol+1,grid,dp);
        }
        if(currcol+1<grid[0].size() && grid[currrow][currcol]<grid[currrow][currcol+1]){
            side=1+solve(currrow,currcol+1,grid,dp);
        }
        if(currrow+1<grid.size() && currcol+1<grid[0].size() && grid[currrow][currcol]<grid[currrow+1][currcol+1]){
            downside=1+solve(currrow+1,currcol+1,grid,dp);
        }
        return dp[currrow][currcol]=max({upside,side,downside});
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            int temp=solve(i,0,grid,dp);
            maxi=max(maxi,temp);
        }
        return maxi;
    }
};