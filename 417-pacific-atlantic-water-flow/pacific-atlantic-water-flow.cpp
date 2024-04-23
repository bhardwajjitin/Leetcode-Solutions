class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>&grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,char>>q;
        vector<vector<int>>ans;
        vector<vector<char>>vis(m,vector<char>(n,'C'));
        vis[0][n-1]='B';
        vis[m-1][0]='B';
        q.push({{0,n-1},'B'});
        q.push({{m-1,0},'B'});
        int di[]={-1,0,0,1};
        int dj[]={0,-1,1,0};
        for(int i=0;i<m-1;i++){
            q.push({{i,0},'P'});
            if(vis[i][0]=='C'){
            vis[i][0]='P';
            }
            else if(vis[i][0]=='A'){
              vis[i][0]='B';
            }
        }
        for(int i=1;i<n-1;i++){
            q.push({{0,i},'P'});
            if(vis[0][i]=='C'){
            vis[0][i]='P';
            }
            else if(vis[0][i]=='A'){
            vis[0][i]='B';
            }
        }
        for(int i=1;i<m;i++){
            q.push({{i,n-1},'A'});
            if(vis[i][n-1]=='C'){
            vis[i][n-1]='A';
            }
            else if(vis[i][n-1]=='P'){
            vis[i][n-1]='B';
            }
        }
        for(int i=1;i<n-1;i++){
            q.push({{m-1,i},'A'});
            if(vis[m-1][i]=='C'){
            vis[m-1][i]='A';
            }
            else if(vis[m-1][i]=='P'){
            vis[m-1][i]='B';
            }
        }
        while(!q.empty()){
           int row=q.front().first.first;
           int col=q.front().first.second;
           char ch=q.front().second;
           q.pop();
           for(int i=0;i<4;i++){
            int nrow=row+di[i];
            int ncol=col+dj[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]>=grid[row][col]){
                if(vis[nrow][ncol]=='B'){
                    continue;
                }
                else if(vis[nrow][ncol]=='C'){
                    q.push({{nrow,ncol},ch});
                    vis[nrow][ncol]=ch;
                }
                else if(vis[nrow][ncol]!='B' && vis[nrow][ncol]!='C' && vis[nrow][ncol]!=ch){
                    q.push({{nrow,ncol},'B'});
                    vis[nrow][ncol]='B';
                }
            }
           }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]=='B'){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};