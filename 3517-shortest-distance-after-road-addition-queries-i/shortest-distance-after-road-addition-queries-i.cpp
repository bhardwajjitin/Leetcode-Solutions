class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>adj[n];
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        vector<int>dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[0]=0;
        pq.push({0,0});
         while(!pq.empty()){
                int node=pq.top().second;
                int distance=pq.top().first;
                pq.pop();
                for(auto it:adj[node]){
                    int adjnode=it;
                    if(dist[it]>distance+1){
                        dist[it]=distance+1;
                        pq.push({dist[it],adjnode});
                    }
                }
            }
            vector<int>ans;
        for(auto it:queries){
            int start=it[0];
            int end=it[1];
            adj[start].push_back(end);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            pq.push({0,0});
            while(!pq.empty()){
                int node=pq.top().second;
                int distance=pq.top().first;
                if(node==n-1){
                    ans.push_back(distance);
                    break;
                }
                pq.pop();
                for(auto it:adj[node]){
                    int adjnode=it;
                    if(dist[it]>=distance+1){
                        dist[it]=distance+1;
                        pq.push({dist[it],adjnode});
                    }
                }
            }
        }
        return ans;
    }
};