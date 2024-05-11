class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adjlist[n+1];
        vector<string>par(n+1);
        for(int i=0;i<=n;i++){
          string temp=to_string(i);
          par[i]=temp;
        }
        for(int i=0;i<dislikes.size();i++){
          int u=dislikes[i][0];
          int v=dislikes[i][1];
          adjlist[u].push_back(v);
          adjlist[v].push_back(u);
        }
        
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++){
        queue<pair<int,string>>q;
        if(vis[i]){
          string temp=par[i];
          q.push({i,temp});
        }
        else{
        vis[i]=1;
        q.push({i,"A"});
        }
        while(!q.empty()){
          int node=q.front().first;
          string type=q.front().second;
          q.pop();
          for(auto it:adjlist[node]){
            if(par[it]==type)return false;
            if(!vis[it]){
              if(type=="A"){
              q.push({it,"B"});
              par[it]="B";
              }
              else{
                q.push({it,"A"});
                par[it]="A";
              }
              vis[it]=1;
            }
          }
        }
        }
        return true;
    }
};