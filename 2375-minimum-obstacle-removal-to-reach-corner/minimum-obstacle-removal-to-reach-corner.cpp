class Solution {
    int dr[4] = {0,1,0,-1} , dc[4] = {1,0,-1,0};
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>minh;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int start = 0;
        if(grid[0][0] == 1)start = 1;
        minh.push({start,0,0});
        while(!minh.empty()){
            auto [currObstacles,currRow,currCol] = minh.top();
            minh.pop();
            if(currRow == grid.size()-1 and currCol == grid[0].size()-1)return currObstacles;
            for(int delta = 0 ; delta < 4; delta++){
                int nRow = currRow+dr[delta] , nCol = currCol+dc[delta];
                if(nRow >= 0 and nCol >= 0 and nRow < grid.size() and nCol < grid[0].size() and vis[nRow][nCol] == 0){
                    vis[nRow][nCol] = 1;
                    int newObs = currObstacles + grid[nRow][nCol];
                    minh.push({newObs,nRow,nCol});
                }
            }
        }
        return 0;
    }
};