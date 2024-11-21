class Solution {
    private:
    void solve(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid,int m,int n){
        // back row wise
        for(int i=row-1;i>=0;i--){
            if(grid[i][col]==1 || grid[i][col]==0){
                break;
            }
            else if(!vis[i][col] && grid[i][col]!=1){
                vis[i][col]=1;
            }
        }
        // front row wise
        for(int i=row+1;i<m;i++){
            if(grid[i][col]==1 || grid[i][col]==0){
                break;
            }
            else if(!vis[i][col] && grid[i][col]!=1){
                vis[i][col]=1;
            }
        }
        //back col wise
        for(int j=col-1;j>=0;j--){
            if(grid[row][j]==1 || grid[row][j]==0){
                break;
            }
            else if(!vis[row][j] && grid[row][j]!=1){
                vis[row][j]=1;
            }
        }
        // front col wise
        for(int j=col+1;j<n;j++){
             if(grid[row][j]==1 || grid[row][j]==0){
                break;
            }
            else if(!vis[row][j] && grid[row][j]!=1){
                vis[row][j]=1;
            }
        }
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m,vector<int>(n,-1));
        int r=guards.size();
        int r1=walls.size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<r;i++){
            int row=guards[i][0];
            int col=guards[i][1];
            grid[row][col]=0;
        }
        for(int i=0;i<r1;i++){
            int row=walls[i][0];
            int col=walls[i][1];
            grid[row][col]=1;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    vis[i][j]=1;
                    solve(i,j,vis,grid,m,n);
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==-1){
                    count++;
                }
            }
        }
        return count;
    }
};