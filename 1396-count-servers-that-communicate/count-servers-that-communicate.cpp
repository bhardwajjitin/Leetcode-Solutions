class Disjoint{
    private:
    vector<int>parent,size;
    public:
    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(node==parent[node])return node;
        return findUPar(parent[node]);
    }
    void unionbysize(int u,int v){
        int U=findUPar(u);
        int V=findUPar(v);
        if(U==V)return;
        if(size[U]>=size[V]){
            parent[V]=U;
            size[U]+=size[V];
        }
        else{
            parent[U]=V;
            size[V]+=size[U];
        }
        return;
    }
    int gettotal(){
        int totalsum=0;
        for(int i=0;i<parent.size();i++){
          if(parent[i]==i && size[i]>1){
            totalsum+=size[i];
          }
        }
        return totalsum;
    }
};
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
      unordered_map<int,pair<int,int>>umapx,umapy;
      int m=grid.size();
      int n=grid[0].size();
      Disjoint ds(m*n);
      for(int i=0;i<m*n;i++){
        int row=i/n;
        int col=i%n;
        if(grid[row][col] == 1) {
                if(umapx.find(row) != umapx.end()) {
                    int prerow = umapx[row].first;
                    int precol = umapx[row].second;
                    int index = prerow * n + precol;
                    ds.unionbysize(row * n + col, index);
                } else {
                    umapx[row] = {row, col};
                }
                if(umapy.find(col) != umapy.end()) {
                    int prerow = umapy[col].first;
                    int precol = umapy[col].second;
                    int index = prerow * n + precol;
                    ds.unionbysize(row * n + col, index);
                } else {
                    umapy[col] = {row, col};
                }
            }
        }
        return ds.gettotal();
    }
};