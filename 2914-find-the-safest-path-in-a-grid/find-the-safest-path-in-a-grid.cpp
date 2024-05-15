class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return 0;
        queue<pair<int,int>>q;
        
        vector<vector<int>>dis(n,vector<int>(n,1e5));
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            if(grid[i][j]==1){
              q.push({i,j});
              dis[i][j]=0;
            }
          }
        }
        int di[]={-1,0,0,1};
        int dj[]={0,-1,1,0};
        while(!q.empty()){
          auto it=q.front();
          q.pop();
          int row=it.first;
          int col=it.second;
          for(int i=0;i<4;i++){
            int nrow=row+di[i];
            int ncol=col+dj[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]!=1 && dis[nrow][ncol]>dis[row][col]+1){
                dis[nrow][ncol]=dis[row][col]+1;
                q.push({nrow,ncol});
            }
          }
        }
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        int ans=INT_MAX;
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({dis[0][0],{0,0}});
        ans=min(ans,dis[0][0]);
        while(!pq.empty()){
          auto it=pq.top();
          pq.pop();
          int dist=it.first;
          int row=it.second.first;
          int col=it.second.second;
          ans=min(ans,dist);
          if(row==n-1 && col==n-1){
            return ans;
          }
          
          for(int i=0;i<4;i++){
            int nrow=row+di[i];
            int ncol=col+dj[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && !vis[nrow][ncol]){
               pq.push({dis[nrow][ncol],{nrow,ncol}});
               vis[nrow][ncol]=1;
            }
          }
        }
        return ans;
    }
};