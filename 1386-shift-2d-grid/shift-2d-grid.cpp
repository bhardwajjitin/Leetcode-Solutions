class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
      int m=grid.size();
      int n=grid[0].size();
      vector<vector<int>>temp=grid;
        while(k--){
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              temp[j][(i+1)%n]=grid[j][i];
            }
          }
          grid=temp;
          for(int i=0;i<m-1;i++){
            temp[i+1][0]=grid[i][0];
          }
          temp[0][0]=grid[m-1][0];
          grid=temp;
        }
        return grid;
    }
};