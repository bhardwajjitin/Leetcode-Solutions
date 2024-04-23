class Solution {
  private:
  void solve(vector<int>adj[],vector<int>&res,int node,int n,vector<vector<int>>&ans){
    res.push_back(node);
    for(auto it:adj[node]){
      solve(adj,res,it,n,ans);
    }
    if(node==n-1){
      ans.push_back(res);
    }
    res.pop_back();
  }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       int n=graph.size();
       vector<int>adj[n];
       for(int i=0;i<n;i++){
          for(int j=0;j<graph[i].size();j++){
            adj[i].push_back(graph[i][j]);
          }
       }
      vector<vector<int>>ans;
      vector<int>res;
      solve(adj,res,0,n,ans);
      return ans;
    }
};