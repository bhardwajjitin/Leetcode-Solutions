class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        set<int>st[n];
        vector<int>indeg(n);
        vector<vector<int>>ans[n];
        vector<vector<int>>arr;
        vector<int>adj[n];
        for(auto it:edges){
          int u=it[0];
          int v=it[1];
          indeg[v]++;
          adj[u].push_back(v);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
          if(indeg[i]==0){
            q.push(i);
            ans[i].push_back({});
          }
        }
        while(!q.empty()){
          int node=q.front();
          q.pop();
          for(auto it:adj[node]){
            indeg[it]--;
            for(auto t:st[node]){
              st[it].insert(t);
            }
            st[it].insert(node);
            if(indeg[it]==0){
              q.push(it);
              vector<int>v;
              for(auto temp:st[it]){
                v.push_back(temp);
              }
              ans[it].push_back(v);
            }
          }
        }
        for(int i=0;i<n;i++){
          for(auto it:ans[i]){
            arr.push_back(it);
          }
        }
        return arr;
    }
};