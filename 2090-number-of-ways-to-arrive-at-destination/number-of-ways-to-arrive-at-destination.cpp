class Solution {
    #define mod 1000000007
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>>adjlist[n];
        for(int i=0;i<roads.size();i++){
            long long u=roads[i][0];
            long long v=roads[i][1];
            long long dis=roads[i][2];
            adjlist[u].push_back({v,dis});
            adjlist[v].push_back({u,dis});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        vector<long long>dist(n,LLONG_MAX),ways(n,1);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            long long dis=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            for(auto it:adjlist[node]){
                long long adjnode=it.first;
                long long edw=it.second;
                if(dist[adjnode]>dis+edw){
                    dist[adjnode]=dis+edw;
                    pq.push({dis+edw,adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(dist[adjnode]==dis+edw){
                    ways[adjnode]+=(ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};