class Solution {
    private:
    vector<int>solve(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&land,int m,int n){
        int endr;
        int endc;
        int di[]={-1,0,0,1};
        int dj[]={0,-1,1,0};
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col]=1;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
           
            endr=r;
            endc=c;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+di[i];
                int ncol=c+dj[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && land[nrow][ncol]==1){
                  q.push({nrow,ncol});
                  vis[nrow][ncol]=1;
                }
            }
        }
        return {row,col,endr,endc};
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m=land.size();
        int n=land[0].size();
        vector<vector<int>>res;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==1 && !vis[i][j]){
                    vector<int>ans=solve(i,j,vis,land,m,n);
                    res.push_back(ans);
                }
            }
        }
        return res;
    }
};