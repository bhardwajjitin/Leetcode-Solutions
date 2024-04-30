class DisjointSet{
  private:
  vector<int>par,rank,size;
  public:
  DisjointSet(int n){
    par.resize(n);
    rank.resize(n,0);
    size.resize(n);
    for(int i=0;i<n;i++){
      par[i]=i;
      size[i]=1;
    }
  }
  int findUPar(int node){
    if(node==par[node])return node;
    return findUPar(par[node]);
  }
  void unionbyrank(int u,int v){
    int ulp_u=findUPar(u);
    int ulp_v=findUPar(v);
    if(ulp_u==ulp_v)return;
    if(rank[ulp_v]<rank[ulp_u]){
      par[ulp_v]=ulp_u;
      rank[ulp_u]+=rank[ulp_v];
    }
    else{
      par[ulp_u]=ulp_v;
      rank[ulp_v]+=rank[ulp_u];
    }
  }
  void unionbysize(int u,int v){
    int ulp_u=findUPar(u);
    int ulp_v=findUPar(v);
    if(ulp_u==ulp_v)return;
    if(size[ulp_v]<size[ulp_u]){
      par[ulp_v]=ulp_u;
      size[ulp_u]+=size[ulp_v];
    }
    else{
      par[ulp_u]=ulp_v;
      size[ulp_v]+=size[ulp_u];
    }
  }

  int solve(set<int>&st){
    int cnt=0;
    for(auto it:st){
      cnt+=size[it];
    }
    return cnt;
  }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        DisjointSet ds(m*n);
        vector<vector<int>>vis(m,vector<int>(n,0));
        int di[]={-1,0,0,1};
        int dj[]={0,-1,1,0};
        for(int i=0;i<m*n;i++){
             int row=i/m;
             int col=i%m;
            if(grid[row][col]==1 && !vis[row][col]){
                queue<int>q;
                q.push(i);
                vis[row][col]=1;
                while(!q.empty()){
                  int node=q.front();
                  row=node/m;
                  col=node%m;
                  q.pop();
                  for(int i=0;i<4;i++){
                    int nr=row+di[i];
                    int nc=col+dj[i];
                    if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                        vis[nr][nc]=1;
                        int temp=(nr*m)+nc;
                        ds.unionbysize(temp,node);
                        q.push(temp);
                    }
                  }
                }
            }
          }
        
        int maxi=0;
        bool flag=true;
        for(int i=0;i<m*n;i++){
          int row=i/m;
          int col=i%m;
          if(grid[row][col]==0){
            int cnt=1;
            flag=false;
            set<int>st;
            for(int k=0;k<4;k++){
              int nr=row+di[k];
              int nc=col+dj[k];
              if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                int temp=(nr*m)+nc;
                int get=ds.findUPar(temp);
                st.insert(get);
              }
            }
            cnt+=ds.solve(st);
            maxi=max(maxi,cnt);
          }
        }  
        if(flag==true){
          return m*n;
        }
     return maxi;
    }
};