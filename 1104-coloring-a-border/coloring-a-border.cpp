class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m=grid.size();
        int n=grid[0].size();
        vector<pair<int,int>>res;
        queue<pair<int,int>>q;
        int di[]={-1,0,0,1};
        int dj[]={0,-1,1,0};
        vector<vector<int>>vis(m,vector<int>(n,0));
        vis[row][col]=1;
        q.push({row,col});
        int prev=grid[row][col];
        while(!q.empty()){
          int r=q.front().first;
          int c=q.front().second;
          q.pop();
          bool flag=true;
          for(int i=0;i<4;i++){
            int nr=r+di[i];
            int nc=c+dj[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==prev){
              vis[nr][nc]=1;
              q.push({nr,nc});
            }
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]!=prev){
               flag=false;
            }
          }
          if(r==0 || c==0 || r==m-1 || c==n-1 || flag==false){
            res.push_back({r,c});
          }
        }
        for(int i=0;i<res.size();i++){
          int r=res[i].first;
          int c=res[i].second;
          grid[r][c]=color;
        }
        return grid;
    }
};