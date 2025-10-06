class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>>pq;
        int di[]={-1,0,0,1};
        int dj[]={0,-1,1,0};
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        vis[0][0]=1;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        int min_time=INT_MAX;
        while(!pq.empty()){
            auto it=pq.top();
            int row=it.second.first;
            int col=it.second.second;
            int time=it.first;
            pq.pop();
            if(row==grid.size()-1 && col==grid[0].size()-1){
               min_time=min(min_time,time);
               break;
            }
            for(int i=0;i<4;i++){
                int nrow=row+di[i];
                int ncol=col+dj[i];
                if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && !vis[nrow][ncol]){
                    pq.push({max(time,grid[nrow][ncol]),{nrow,ncol}});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return min_time;
    }
};