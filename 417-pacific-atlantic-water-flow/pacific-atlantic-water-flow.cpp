class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>vis(m,vector<int>(n,-1)),ans;
        set<pair<int,int>>atlan,paci;
        int di[]={-1,0,0,1};
        int dj[]={0,-1,1,0};
        for(int i=0;i<m;i++){
            atlan.insert({i,n-1});
            paci.insert({i,0});
        }
        for(int i=0;i<n;i++){
            atlan.insert({m-1,i});
            paci.insert({0,i});
        }
        while(!atlan.empty()){
            auto it=*atlan.begin();
            atlan.erase(it);
            int row=it.first;
            int col=it.second;
            vis[row][col]=0;
            for(int i=0;i<4;i++){
                int nrow=row+di[i];
                int ncol=col+dj[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && heights[nrow][ncol]>=heights[row][col] && vis[nrow][ncol]==-1){
                    atlan.insert({nrow,ncol});
                }
            }
        }
       
         while(!paci.empty()){
            auto it=*paci.begin();
            paci.erase(it);
            int row=it.first;
            int col=it.second;
           vis[row][col] = (vis[row][col] == -1) ? 1 : (vis[row][col] == 0) ? 2 : vis[row][col];
            for(int i=0;i<4;i++){
                int nrow=row+di[i];
                int ncol=col+dj[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && heights[nrow][ncol]>=heights[row][col] && (vis[nrow][ncol]==-1 || vis[nrow][ncol]==0)){
                    paci.insert({nrow,ncol});
                }
            }
        }
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==2){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};