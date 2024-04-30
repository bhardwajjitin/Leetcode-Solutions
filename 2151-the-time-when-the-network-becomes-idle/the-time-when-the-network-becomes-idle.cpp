class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& pat) {
        int n=pat.size();
        vector<int>dis(n,1e9);
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
          int u=edges[i][0];
          int v=edges[i][1];
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
        set<pair<int,int>>st;
        st.insert({0,0});
        dis[0]=0;
        while(!st.empty()){
          auto it=*(st.begin());
          int node=it.second;
          int dist=it.first;
          st.erase(it);
          for(auto it:adj[node]){
            if(dist+1<dis[it]){
                if(dis[it]!=1e9){
                  st.erase({dis[it],it});
                }
                dis[it]=dist+1;
                st.insert({dis[it],it});
            }
          }
        }
      
      int mini=-1e9;
      for(int i=1;i<n;i++){
        int dist=2*dis[i];
        int time=dist%pat[i];
        int res;
        if(time==0){
          res=2*dist-pat[i]+1;
        }
        else{
          res=2*dist-time+1;
        }
        mini=max(mini,res);
      }
      return mini;
    }
};