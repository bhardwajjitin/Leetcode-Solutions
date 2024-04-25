class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>indegree(m,vector<int>(n,0));
        int di[]={-1,0,0,1};
        int dj[]={0,-1,1,0};
        map<pair<int,int>,vector<pair<int,int>>>mp;
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
             for(int k=0;k<4;k++){
              int nrow=i+di[k];
              int ncol=j+dj[k];
              if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && matrix[nrow][ncol]>matrix[i][j]){
                indegree[nrow][ncol]++;
                mp[{i,j}].push_back({nrow,ncol});
              }
             }
          }
        }
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(indegree[i][j]==0){
              q.push({{i,j},1});
            }
          }
        }
        int maxi=0;
        while(!q.empty()){
          int r=q.front().first.first;
          int c=q.front().first.second;
          int dis=q.front().second;
          q.pop();
          maxi=max(maxi,dis);
          for(auto it:mp[{r,c}]){
              int row=it.first;
              int col=it.second;
              indegree[row][col]--;
              if(indegree[row][col]==0){
                q.push({{row,col},dis+1});
              }
          }
        }
        return maxi;
    }
};