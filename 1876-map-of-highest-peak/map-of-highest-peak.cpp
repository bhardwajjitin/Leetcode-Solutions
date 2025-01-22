class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row=isWater.size();
        int col=isWater[0].size();
        vector<vector<int>>vis(row,vector<int>(col,0));
        queue<tuple<int,int,int>>q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(isWater[i][j]==1){
                    q.push({i,j,0});
                    isWater[i][j]=0;
                    vis[i][j]=1;
                }
            }
        }
        int di[]={-1,0,0,1};
        int dj[]={0,-1,1,0};
        while(!q.empty()){
            auto [currrow,currcol,dist]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=currrow+di[i];
                int ncol=currcol+dj[i];
                if(nrow>=0 && nrow<row && ncol>=0 && ncol<col && !vis[nrow][ncol]){
                    q.push({nrow,ncol,dist+1});
                    vis[nrow][ncol]=1;
                    isWater[nrow][ncol]=dist+1;
                }
            }
        }
        return isWater;
    }
};