class Solution {
    private:
    bool check(vector<int>adj[],int source,vector<int>&vis,int dest){
        vis[source]=1;
        if(source==dest)return true;
        for(auto it:adj[source]){
            if(!vis[it]){
                if(check(adj,it,vis,dest))return true;
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        return check(adj,source,vis,destination);
    }
};