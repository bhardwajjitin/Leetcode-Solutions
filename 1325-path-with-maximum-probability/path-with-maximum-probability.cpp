class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double>dis(n,1e9);
        vector<pair<int,double>>adj[n];
        dis[start_node]=1;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        queue<int>pq;
        pq.push(start_node);
        while(!pq.empty()){
            int node=pq.front();
            pq.pop();
            for(auto it:adj[node]){
                double weight=it.second;
                int adjnode=it.first;
                if(dis[adjnode]==1e9){
                    dis[adjnode]=dis[node]*weight;
                    pq.push(adjnode);
                }
                else if(dis[adjnode]<dis[node]*weight){
                    dis[adjnode]=dis[node]*weight;
                    pq.push(adjnode);
                }
            }
        }

        return dis[end_node]==1e9?0:dis[end_node];
    }
};