class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int di[]={-1,0,0,1};
        int dj[]={0,-1,1,0};
        vector<vector<int>>vis(m,vector<int>(n,k+1));
        queue<pair<int,pair<pair<int,int>,int>>>st;
        st.push({0,{{0,0},0}});
        vis[0][0]=0;
        while(!st.empty()){
            auto it=st.front();
            st.pop();
            int row=it.second.first.first;
            int col=it.second.first.second;
            int dis=it.second.second;
            int obs=it.first;
            if(row==m-1 && col==n-1)return dis;
            for(int i=0;i<4;i++){
                int nrow=row+di[i];
                int ncol=col+dj[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                    if(grid[nrow][ncol]==1 && obs+1<vis[nrow][ncol] && obs+1<=k){
                        vis[nrow][ncol]=obs+1;
                        st.push({obs+1,{{nrow,ncol},dis+1}});
                    }
                    else if(grid[nrow][ncol]==0 && obs<vis[nrow][ncol]){
                        vis[nrow][ncol]=obs;
                        st.push({obs,{{nrow,ncol},dis+1}});
                    }
                }
            }
        }
        return -1;
    }
};