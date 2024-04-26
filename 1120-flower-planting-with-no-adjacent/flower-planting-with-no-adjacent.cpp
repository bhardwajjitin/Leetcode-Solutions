class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int>vis(n+1);
        vector<int>adj[n+1];
        for(int i=0;i<paths.size();i++){
          int u=paths[i][0];
          int v=paths[i][1];
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
        vector<int>flower(n,0);
        for(int i=1;i<=n;i++){
          if(!vis[i]){
          queue<int>q;
          q.push(i);
          vis[i]=1;
          while(!q.empty()){
            int top=q.front();
            q.pop();
            set<int>st;
            for(auto it:adj[top]){
              if(flower[it-1]!=0){
                st.insert(flower[it-1]);
              }
              if(!vis[it]){
                vis[it]=1;
                q.push(it);
              }
            }
            for(int i=1;i<=4;i++){
              if(st.find(i)==st.end()){
                flower[top-1]=i;
              }
            }
          }
        }
      }
      return flower;
    }
};