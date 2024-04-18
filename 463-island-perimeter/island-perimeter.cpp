class Solution {
    private:
    int solve(vector<vector<int>>&grid,vector<int>&di,vector<int>&dj,vector<vector<int>>&vis,int i,int j){
          queue<pair<int,int>>pq;
          int m=grid.size();
          int n=grid[0].size();
          int cnt=0;
          pq.push({i,j});
          vis[i][j]=1;
          while(!pq.empty()){
              int row=pq.front().first;
              int col=pq.front().second;
              pq.pop();
              for(int k=0;k<4;k++){
                  int nrow=row+di[k];
                  int ncol=col+dj[k];
                  if(nrow<0 || ncol<0 || ncol>=n || nrow>=m || (nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol]==0))cnt++;
                  else if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                      vis[nrow][ncol]=1;
                      pq.push({nrow,ncol});
                  }
              }
          }
          return cnt;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ans;
        vector<int>di={-1,0,0,1};
        vector<int>dj={0,-1,1,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                   ans=solve(grid,di,dj,vis,i,j);
                }
            }
        }
        return ans;
    }
};