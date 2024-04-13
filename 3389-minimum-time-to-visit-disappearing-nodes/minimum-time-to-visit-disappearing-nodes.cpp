class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int>dis(n,1e9);
        dis[0]=0;
        vector<int>ans(n,-1);
        map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        set<pair<int,int>>q;
        q.insert({0,0});
        while(!q.empty()){
            auto it=*q.begin();
            q.erase(*q.begin());
            int node=it.second;
            int dist=it.first;
            if(dist>=disappear[node]){
                continue;
            }
            for(auto temp:adj[node]){
                int v=temp.first;
                int wt=temp.second;
                if(dis[v]>wt+dis[node]){
                    if(dis[v]!=1e9){
                        q.erase({dis[v],v});
                    }
                    dis[v]=wt+dis[node];
                    if(dis[v]<disappear[v]){
                    q.insert({dis[v],v});
                    }
                }
            }     
        }
        for(int i=0;i<n;i++){
           if(disappear[i]>dis[i]){
               ans[i]=dis[i];
           }
        }
        return ans;
    }
};