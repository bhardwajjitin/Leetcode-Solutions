class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>grid(n,vector<int>(n,INT_MAX));
        for(int i=0;i<edges.size();i++){
          int u=edges[i][0];
          int v=edges[i][1];
          int wt=edges[i][2];
          grid[u][v]=wt;
          grid[v][u]=wt;
        }
        for(int j=0;j<n;j++){
         for(int i=0;i<n;i++){
          for(int k=0;k<n;k++){
                if(grid[i][j]!=INT_MAX && grid[j][k]!=INT_MAX && grid[i][k]>grid[i][j]+grid[j][k]){
                  grid[i][k]=grid[i][j]+grid[j][k];
                }
              }
            }
          }
      int ans=-1;
      int mini=n;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]<=distanceThreshold && i!=j){
                    count++;
                }
            }
            if(mini>=count){
                mini=count;
                ans=i;
            }
        }
        return ans;
    }
};