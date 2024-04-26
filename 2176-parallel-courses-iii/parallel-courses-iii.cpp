class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>adj[n+1];
        int m=relations.size();
        vector<int>indegree(n+1,0);
        for(int i=0;i<m;i++){
          int u=relations[i][0];
          int v=relations[i][1];
          adj[u].push_back(v);
          indegree[v]++;
        }
      priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
      for(int i=1;i<=n;i++){
        if(indegree[i]==0){
          pq.push({time[i-1],i});
        }
      }
      int ans=0;
      while(!pq.empty()){
        auto it=pq.top();
        int dis=it.first;
        int node=it.second;
        ans=max(ans,dis);
        pq.pop();
        for(auto temp:adj[node]){
          indegree[temp]--;
          if(indegree[temp]==0){
            pq.push({dis+time[temp-1],temp});
          }
        }
      }
      return ans;
    }
};