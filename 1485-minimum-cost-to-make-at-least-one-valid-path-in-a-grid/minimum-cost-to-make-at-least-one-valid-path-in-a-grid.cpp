class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rowsize = grid.size();
        int colsize = grid[0].size();
        int di[] = {0, 0, 1, -1};
        int dj[] = {1, -1, 0, 0};
        int dir[] = {0, 1, 2, 3};
        vector<vector<int>> vis(rowsize, vector<int>(colsize, 1e5));
        vis[0][0] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        while (!q.empty()) {
            auto it = q.front();
            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();
            int target = dir[grid[row][col] - 1];

            for (int i = 0; i < 4; i++) {
                int newr = row + di[i];
                int newc = col + dj[i];
                if (newr >= 0 && newr < rowsize && newc >= 0 &&
                    newc < colsize) {
                    int cost = (i == target) ? 0 : 1;
                    if(vis[newr][newc]>dist+cost){
                    q.push({dist+cost, {newr, newc}});
                    vis[newr][newc] = min(vis[newr][newc], dist + cost);
                    }
                }
            }
        }
        return vis[rowsize-1][colsize-1];
    }
};