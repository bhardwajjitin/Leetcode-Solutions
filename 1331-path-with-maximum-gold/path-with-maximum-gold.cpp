class Solution {
  private:
  int solve(vector<vector<int>>&grid,int i,int j,int m,int n){
    if(i<0 || j<0 || i>=m || j>=n)return 0;
    int down=grid[i][j];
    int right=grid[i][j];
    int left=grid[i][j];
    int up=grid[i][j];
    if(i+1<m && grid[i+1][j]!=0){
        int temp=grid[i][j];
        grid[i][j]=0;
        down+=solve(grid,i+1,j,m,n);
        grid[i][j]=temp;
    }
    if(i-1>=0 && grid[i-1][j]!=0){
       int temp=grid[i][j];
        grid[i][j]=0;
        up+=solve(grid,i-1,j,m,n);
        grid[i][j]=temp;
    }
    if(j+1<n && grid[i][j+1]!=0){
       int temp=grid[i][j];
        grid[i][j]=0;
        right+=solve(grid,i,j+1,m,n);
        grid[i][j]=temp;
    }
    if(j-1>=0 && grid[i][j-1]!=0){
       int temp=grid[i][j];
        grid[i][j]=0;
        left+=solve(grid,i,j-1,m,n);
        grid[i][j]=temp;
    }
    return max(down,max(right,max(left,up)));
  }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxi=0;
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              if(grid[i][j]!=0){
               
                maxi=max(maxi,solve(grid,i,j,m,n));
              }
          }
        }
        return maxi;
    }
};