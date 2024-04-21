class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        set<pair<int,pair<int,int>>>pq;
        pq.insert({0,{0,0}});
        vis[0][0]=1;
        int di[]={-1,0,0,1};
        int dj[]={0,-1,1,0};
        while(!pq.empty()){
            auto it=*pq.begin();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.erase(*pq.begin());
            vis[row][col]=1;
            if(row==m-1 && col==n-1)return dis;
            for(int i=0;i<4;i++){
                int nrow=row+di[i];
                int ncol=col+dj[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol]){
                    if(grid[nrow][ncol]==1){
                        pq.insert({dis+1,{nrow,ncol}});
                    }
                    else{
                        pq.insert({dis,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};